#include <iostream>
#include <memory>
#include <stack>

// Business layer
class TextEditor {
    public:
        void insertText(std::string textToBeAppended) {
            content += textToBeAppended;
        }
        void deleteText(size_t lengthToBeDeleted) {
            if (content.size() >= lengthToBeDeleted) {
                content.erase(content.size() - lengthToBeDeleted);
            }
        }
        std::string getContent() {
            return content;
        }
    private:
        std::string content;
};

class ICommand {
    public:
        virtual void execute() = 0;
        virtual void unExecute() = 0; 
        virtual ~ICommand() = default;
};

class InsertCommand: public ICommand {
    public:
        InsertCommand(TextEditor& te,const std::string& text): m_te(te), m_text(text) {}
        void execute() override {
            m_te.insertText(m_text);
        }
        // This method is not directly exposed to client, only command managers uses it for
        // undo actions. So it is safe to provide only the size of text and not mandatory to
        // check the precense of substring presence in content.
        void unExecute() override {
            m_te.deleteText(m_text.size());
        }
    private:
        TextEditor& m_te;
        std::string m_text;
};

class DeleteCommand: public ICommand {
    public:
        DeleteCommand(TextEditor& te, size_t length): m_te(te), m_len(length), m_deletedText("") {}
        void execute() override {
            if (m_len > m_te.getContent().size()) {
                std::cout << "Unable to delete - length mismatch" << std::endl;
                return;
            }
            // substr (index) - creates substring from index mentioned to end.
            m_deletedText = m_te.getContent().substr(m_te.getContent().size() - m_len);
            m_te.deleteText(m_len);
        }
        void unExecute() override {
            m_te.insertText(m_deletedText);
        }
    private:
        TextEditor& m_te;
        size_t m_len;
        std::string m_deletedText;
};

class CommandManager {
    public:
    void executeCommand(std::unique_ptr<ICommand> commandInstance) {
        if (nullptr != commandInstance) {
            commandInstance->execute();
            undoStack.emplace(std::move(commandInstance));
            while (!redoStack.empty()) redoStack.pop();
        }
    }

    bool undo() {
        // unexecute command and add the command to redo stack
        if (!undoStack.empty()) { 
            std::unique_ptr<ICommand> commandInstance = std::move(undoStack.top());
            commandInstance->unExecute();
            undoStack.pop();
            redoStack.push(std::move(commandInstance));
            return true;
        } else {
            std::cout << "Nothing to undo" << std::endl;
        }
        return false;
    }

    bool redo() {
        if (!redoStack.empty()) {
            std::unique_ptr<ICommand> commandInstance = std::move(redoStack.top());
            commandInstance->execute();

            redoStack.pop();
            undoStack.emplace(std::move(commandInstance));
            return true;
        } else {
            std::cout << "Nothing to redo" << std::endl;
        }
        return false;
    }
    private:
        std::stack<std::unique_ptr<ICommand>> undoStack;
        std::stack<std::unique_ptr<ICommand>> redoStack;
};

// UI layer
int main() {
    TextEditor te;
    CommandManager cm;

    cm.executeCommand(std::make_unique<InsertCommand>(te, "Hello "));
    cm.executeCommand(std::make_unique<InsertCommand>(te, "World "));
    cm.executeCommand(std::make_unique<InsertCommand>(te, "Here"));

    std::cout << te.getContent() << std::endl; // Hello World Here

    cm.executeCommand(std::make_unique<DeleteCommand>(te, 4)); 
    std::cout << te.getContent() << std::endl; // Hello World

    cm.redo(); // Nothing to redo
    cm.undo();
    std::cout << te.getContent() << std::endl; // Hello World Here
    cm.undo();
    std::cout << te.getContent() << std::endl; // Hello World
    cm.redo();
    std::cout << te.getContent() << std::endl; // Hello World Here

    return 0;
}
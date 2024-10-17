#include <iostream>
#include <stack>

// Memento Class
class Memento {
    public:
        Memento(const std::string& textState): m_textState(textState) {}
        std::string getTextState() const {
            return m_textState;
        }
    private:
        std::string m_textState;
};

class CareTaker;

class TextEditor {
    public:
        void appendText(const std::string& text) {
            std::cout << "appending text:" << text << std::endl;
            m_text += text;
        }

        friend class CareTaker;

    private:

        Memento getMemento() {
            std::cout << m_text<< std::endl;
            return Memento(m_text);
        }
        
        void restoreMemento(Memento memento) {
            m_text = memento.getTextState();
            std::cout << m_text << std::endl;
        }

        std::string m_text;
};

class CareTaker {
    public:
        CareTaker(TextEditor& te): m_textEditor(te) {}

        bool undo() {
            if (!m_undoStack.empty()) {
                // remove from undo stack
                Memento memento = m_undoStack.top();
                m_undoStack.pop();

                // push to redo stack
                m_redoStack.push(memento);

                // restore the old state
                if (!m_undoStack.empty()) {
                    m_textEditor.restoreMemento(m_undoStack.top());
                   
                } else {
                    std::cout << "only one item added to undo stack, empty old state" << std::endl;
                    
                }   
                return true;
            } else {
                std::cout << "nothing added to perform undo" << std::endl;
                return false;
            }
        }

        bool redo() {
            if (!m_redoStack.empty()) {
                // remove item from redo stack
                Memento memento = m_redoStack.top();
                m_redoStack.pop();

                // push item to undo stack
                m_undoStack.push(memento);

                // restore the editor state
                m_textEditor.restoreMemento(memento);
                return true;
            } else {
                std::cout << "Redo stack is empty, nothing to redo" << std::endl;
                return false;
            }
        }

        bool save() {
            while (!m_redoStack.empty()) {
                m_redoStack.pop();
            }
            m_undoStack.push(m_textEditor.getMemento());
            return true;
        }

    private:
        std::stack<Memento> m_undoStack;
        std::stack<Memento> m_redoStack;
        TextEditor& m_textEditor;
};

// client or driver code
int main() {
    TextEditor te;
    CareTaker c(te);
    
    te.appendText("Hi ");
    c.save();
    te.appendText("Iam ");
    c.save();
    te.appendText("Ravi ");
    c.save();

    c.undo(); // restore to Hi Iam 
    c.undo(); // restore to Hi
    
    c.redo(); // restore to Hi Iam 
    te.appendText("Rv ");
    c.save();
    
    c.redo(); // no op
    
    return 0;
}
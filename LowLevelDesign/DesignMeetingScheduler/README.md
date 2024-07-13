# Meeting Scheduler

## Common assumptions to avoid
* Meeting scheduling assistant in outlook where it check for availability of user from validating the contents in their calendar. We are not planning to design service drivern or cloud driven solution, it is individual solution i.e for user. We can update calender in cloud to support this functionality later.
* Designing application in cloud centric way
* Confusion in association of classes

## High level Overview
* Schedule meetings for group of participants
* System should help in sending notification for group of people. Note notification are of 2 types "Schedule/Cancelled"
* Organizer can add participants after meeting is scheduled.

## Questions to be clarified
### Room Related
* How available rooms are identified ?
    * There should be meeting room class which maintains isOccupied state, with timestamp the meetings are booked / there can be centralized meeting room look up where users can query its available states. In lld always avoid having centralized mechanism like services.
* How important is capacity of room for meeting ?
    * when user is attempting to schedule meeting for 5, if only larger rooms are available than 5, is it okay to book that ? or + or - 2 is okay to be booked.

### Attendees Related
* How attendees availability is identified ?
* How system access meeting details of all attendees ?

## Requirements (Story in steps)
* n rooms
* capacity of rooms need to known
* availability status of room
* notificaiton mechanism, note: user should get notification whether they are available or not.
* user should have access to calendat to cancel / schedule meetings

## Use cases
* Identified actors from above requirements Users, Calendar, MeetingRooms, MeetingDetails (Date, Interval(startTime, endTime))
* Identified actions from above schedule / cancel , other side users can accept / reject, these are notifications.


### Primary Happy Path Use Case (Do this to identify actors and actions, actors are member variables / classes and actions as methods)

* [Precondition] Organizer (user) should know
    * start time of meeting
    * end time of meeting
    * number of users and their details like emailid
* Organizer wanna know list of available rooms for 'n' users.
* If room is available, then Organizer should send notifications to all users.
    * If Organizer decides to cancel the meeting, there should be way to send meeting cancelled notification.
* Happy meeting !


Considering seperation on concerns principle Notification mechanism should be taken care by differnt module and meeting scheduling should be using notification module.

### Component & associated Actions Identified as follows,
* Organizer
    - check for available meeting rooms
    - schedule meeting
* Recipients
    - Respond to meeting invite (Accept / reject)
* MeetingScheduler
* Notifier
* Meeting
* Room
* Interval
* Calendar


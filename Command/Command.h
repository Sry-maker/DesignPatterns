#pragma once
/**
 * The Command interface declares a method for executing a command.
 */
class Command {
public:
    virtual ~Command() {
    }
    virtual void Execute() const = 0;
};
/**
 * Commands can delegate operations to other objects,
 * called "receivers."
 */
template<typename Receiver>
class EnterCommand : public Command {
    typedef void(Receiver::* Action)();
private:
    Action _action;
    Receiver* _receiver;

public:
     EnterCommand(Receiver* receiver, Action action) : _receiver(receiver), _action(action){
     }

    void Execute() const override {
        (_receiver->*_action)();
    }
};

/**
 * The Receiver classes contain some important business logic. They know how to
 * perform all kinds of operations, associated with carrying out a request. In
 * fact, any class may serve as a Receiver.
 */
class VipPassage {
public:
    void EnterVipPassage() {
        std::cout << "������ͨ��"<< std::endl<< std::endl;
    }
};

class NormalPassage
{
public:
    void EnterNormalPassage() {
        std::cout << "������ͨͨ��" << std::endl << std::endl;
    }
};

class SpecialPassage
{
public:
    void EnterSpecialPassage() {
        std::cout << "������������ͨ��" << std::endl << std::endl;
    }
};


/**
 * The Invoker is associated with one or several commands. It sends a request to
 * the command.
 * The Invoker does not depend on concrete command or receiver classes. The
 * Invoker passes a request to a receiver indirectly, by executing a command.
 */

std::string person[3] = { "С��","С��","С��" };

class Invoker {
    
public:
    std::queue<Command*> commands;
    void Enter() {
        std::cout << "������ģ�����ƥ���˶��᲻ͬ��ݵ���ͨ����ͬͨ���볡�ĳ�����ʹ����Command--����ģʽ"<< std::endl<< std::endl;
        std::cout << "��ʼ�볡" << std::endl << std::endl;
        for (std::string i : person)
        {
            std::cout << i;
            commands.front()->Execute();
            commands.pop();
        }
    }
};
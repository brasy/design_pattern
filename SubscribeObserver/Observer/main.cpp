#include "concrete_observer.h"
#include "concrete_subject.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    std::unique_ptr<ConcreteSubject> sub = std::make_unique<ConcreteSubject>();
    std::shared_ptr<Observer> ob1 = std::make_shared<ConcreteObserver>("mary");
    std::shared_ptr<Observer> ob2 = std::make_shared<ConcreteObserver>("bob");

    sub->attach(ob1);
    sub->attach(ob2);

    sub->setValue(2.0);
    sub->notify();

    sub->detach(ob1);
    sub->setValue(12.0);
    sub->notify();

    return 0;
}

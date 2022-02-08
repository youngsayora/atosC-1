

#include <iostream>
#include <cstring>

using namespace std;

struct list {
    int field;
    list* next;
};

struct Stack {
    list* head;
};

void Push(Stack* stack, int x) {
    list* tmp = new list{ x, stack->head };
    stack->head = tmp;
}

int Pop(Stack* stack) {
    list* tmp = stack->head;
    int value = tmp->field;
    stack->head = stack->head->next;
    delete tmp;
    return value;
}

int Top(const Stack* stack) {
    return stack->head->field;
}

int main() {
    char s[5];
    Stack stack{ 0 };
    while(true){
        cin >> s;
        if (strcmp(s, "push") == 0) {
            int x;
            cin >> x;
            Push(&stack, x);
            cout << "ok" << endl;
        }
        if (strcmp(s, "pop") == 0) {
            int x = Pop(&stack);
            cout << x << endl;
        }
        if (strcmp(s, "back") == 0) {
            int x = Top(&stack);
            cout << x << endl;
        }
        
    }
    return 0;
}


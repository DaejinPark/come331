# Stack

이제 본격적으로 자료구조를 설계하고 구현해보도록 하자. 가장 기본이 되는 가장 저수준의 자료구조를 struct를 이용하여 다음과 같이 정의해보자. 

## struct를 이용한 기본 노드 자료형 정의

``` C
struct node {
    int data;
};

main() {
    struct node n1;
    n1.data = 10;
}
```

자료구조의 기본 노드를 위와 같이 구성하였다면 자료구조의 최소단위인 노드는 단지 정수형 데이타 하나만 포함할 수 있다. 자료형 자체를 노드에 포함하기 보다 외부에 정의된 데이타를 가르키는 포인터 즉 주소만 포함하는 것이 유리하다. 이는 포인터 주소는 일정한 크기를 가지기 때문에 메모리 용량과 처리속도 측면에서 유리함을 의미한다. 포인터를 이용하여 자료구조를 개선해보자.

``` C
struct node {
    int* data;
};

main() {
    // node for holding integer
    struct node n1;
    int a=10;

    n1.data = &a;

    // node for holding float, but error happens
    struct node n2;
    float b = 76.4;

    n2.data = &b;
}
```

자료구조의 기본 단위인 노드에 포함할 데이타가 이제 정수형을 가르키는 포인터가 되었다. 아직까지 정수형 데이타만 노드에 저장할 수 있으므로 여전히 불편하다. 두번째 n2라는 노드가 float 변수를 담을려고 시도해보지만 에러가 발생함을 알 수 있다. 이 코드는 다음과 같이 변형되어야 한다. 알려진 데이타만을 포함할 수 있으며 매번 새로운 자료구조를 추가해야하는 불편함이 생긴다.

``` C
struct node_int {
    int* data;
};
struct node_float {
    float* data;
};

main() {
    // node for holding integer
    struct node_int n1;
    int a=10;

    n1.data = &a;

    // node for holding float, but error happens
    struct node_float n2;
    float b = 45.5;

    n2.data = &b;
}
```

## void* 자료형의 활용

이제 void*를 이용하여 변형해보자. void*에 대한 사용법은 C언어 2시간만에 복습하기편을 참고한다.

``` C
struct node{
    void* data;
};

main() {
    struct node n1;
    int a = 10;
    n1.data = &a

    int* a_p = (int*)n1.data;
    printf("data of n1: %d\n", *a_p);

    struct node n2;
    float b = 44.5;
    n2.data = &b;

    float* b_p = (float*)n2.data;
    printf("data of n2: %f\n", *b_p);
}
```

## 노드간에 관계성 표현

이제 자료구조의 기본인 노드가 다른 노드를 가르키도록 연결성을 표현해보자. C언어에서 제공하는 포인터를 이용하연 노드와 노드 사이에 한방향의 관계가 쉽게 표현된다. 

``` C
struct node {
    void* data;
    struct node* link;
};

main() {
    struct node n1;
    struct node n2;

    n1.link = &n2;
    n2.link = &n1;
}
```

노드와의 관계를 이용하여 전체 자료구조에 쉽게 접근가능하다. 아래 예를 살펴보자. 정의된 노드형은 다음 노드와의 링크를 포함함으로써 재귀적으로 전체 데이타에 대한 추상적인 데이터 형이 한번에 정의되는 효과를 가져온다. 따라서 자료구조의 기본 뼈대는 노드를 위한 struct 형으로 충분하다.

``` C
struct node {
    void* data;
    struct node* link;
};

main() {
    struct node n1;
    int a=10;
    n1.data = &a;

    struct node n2;
    int b=10;
    n2.data = &b;

    printf("node 'a': %d\n", *((int*)n1.data));
    printf("node 'b': %d\n", *((int*)n1.link.data));
}
```

매번 struct node를 사용하지 않고 한개의 자료형으로 재정의하고 싶을때 typdef를 이용하면된다. 다음의 코드를 살펴보자.

``` C
typde struct node {
    void* data;
    struct node* link;
} NODE;

main() {
    NODE n1;
    int a = 10;
    n1.data = &a;

    NODE n1;
    int b = 20;
    n2.data = &b;
}
```

## STACK 자료형 정의

기본 자료향인 node를 정의하였으므로 이제 stack이라는 전체 자료형을 정의해보자. stack은 내부에 포함된 node의 갯수와 최상위 첫번째 node를 가르키는 포인터 변수만 포함하면된다. 이는 stack의 데이타 삽입, 삭제가 최상위 데이터에서만 발생하기 때문다. 다음의 stack의 자료형에 대한 코드를 살펴보자.

``` C
struct STACK {
    int count;
    STACK_NODE* top;
};
```

STACK이라는 이름의 struct 자료형을 정의하였고 내부에 노드 갯수와 최상위 첫번째 노드를 가르키는 포인터 변수로 구성된다. 위에서도 서술한 것 처럼 첫번째 노드로부터 연결된 노드와의 관계를 통해 전체 노드 데이터에 쉽게 접근가능하다. 개별 노드에 대한 자료형을 합쳐서 Stack을 위한 자료구조는 다음과 같이 정의될 수 있다.

``` C
struct STACK {
    int count;
    STACK_NODE* top;
};

typdef struct node {
    void* data;
    struct node* link;
} STACK_NODE;

```

위에 정의된 STACK 자료형에 대한 코드를 ADT_stack.h에 저장하자.

이제 자료구조를 구성하는 기본 자료형을 정의하였으므로 이제 이를 활용하여 다양한 처리를 수행하는 함수를 정의하자. 기본 자료형과 (여기서는 NODE)과 함수를 합하여 추상형 자료형이라고 부르기로 하였다. 스택 생성, 데이터 삽입 (push), 데이터 읽기/삭제 (pop)을 위한 함수를 구현해보자.


### Stack 생성: create_stack()

그럼 이제 stack 자료구조를 생성하는 함수를 정의해보자. stack을 생성하기 위해 입력으로 정의할 파라메터는 따로없다. 그냥 blank stack 자료구조를 하나 생성하면 되기 때문이다. 함수의 실행결과로 생성된 STACK 자료구조의 포인터를 리턴하면 된다. 따라서 사용자는 이런 형태로 함수를 이용할 것이다.

``` C
#include "ADT_stack.h"

main() {
    STACK* new_stack = create_stack();
}
```

이제 create_stack() 함수의 프로토타입을 먼저 정의하고 그것을 ADT_stack.h에 저장한다. 이제 ADT_stack.h의 코드는 다음과 같이 정의된다.

``` C
struct STACK {
    int count;
    STACK_NODE* top;
};

typdef struct node {
    void* data;
    struct node* link;
} STACK_NODE;

STACK* create_stack();

```

create_stack() 함수의 body는 별도의 파일 ADT_stack.c에 구현하도록 한다. 먼저 malloc 함수를 이용하여 STACK 자료형을 담을 공간을 할당받는다. malloc에 대해서는 [2장](../02_C_Review)의 내용을 참고한다. struct로 정의된 각 맴버 변수의 값을 초기화 한다. 내부에 노드가 하나도 없으므로 count는 0이 되고 stack의 top의 위치는 NULL이 되어야 한다. 다음과 같이 코드를 작성하면 된다.

``` C
STACK* create_stack() {
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    stack->count = 0;
    stack->top = NULL;
    return stack;
}
```

### 데이터 Push

이제 준비된 데이타를 stack 자료구조에 삽입해보자. 삽입할 데이타가 먼저 준비되어 있어야 하며 stack에는 단지 데이타의 주소만 전달하기로 하였다. 따라서 데이타 삽입을 위한 push 함수의 입력 인자로는 삽입대상이 되는 stack과 데이타의 주소가 되어야 한다. 리턴값은 함수 실행의 성공/실패를 리턴하기로 하자. 먼저 ADT_stack.h에 push 함수의 프로토타입을 먼저 정의해야 한다.

``` C
ADT_stack.h

... 
bool push(STACK* stack, void* in);
```

이 함수를 이용하여 사용자는 다음과 같은 행태로 데이타 삽입을 구현할 것이다.

``` C
main.c

main() {
    STACK* stack = create_stack();
    int a = 10;
    int b = 20;
    bool result;
    
    result = push(stack, &a);
    if(result == false)
        printf("error happens\n");
        
    result = push(stack, &b);
    if(result == false)
        printf("error happens\n");
     
}
```



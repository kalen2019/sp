# 巨集展開

```
gcc -E max.c -o max.i
```

## max.c 展開前

```c
#define MAX(a,b) ((a)>(b))?(a):(b))

int main() {
  int a=3, b=5;
  int c = MAX(a,b);
  printf("c=%d\n", c);
}
```

## 展開後 => max.i

```c
int main() {
  int a=3, b=5;
  int c = ((a)>(b))?(a):(b));
  printf("c=%d\n", c);
}

```


#include<stdio.h>
//如果只有一级台阶，n = 1, 很明显只有一种跳法
//如果有两级台阶，n = 2，则有两种跳法，一种是跳两下1级，一种是直接跳两级
////1.第n层台阶是从第n - 1层跳1级上来的
////2.第n层台阶是从第n - 2层直接跳2级上来的
////所以可以得到n层的跳法总数是F(n) = F(n - 1) + F(n - 2)
int f(int n) {

	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return f(n - 1) + f(n - 2);
}

int main() {
	int i;
	scanf("%d", &i);
	printf("%d\n", f(i));
}
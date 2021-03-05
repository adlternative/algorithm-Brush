//
// Created by adl on 2020/9/27.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 8
#define COL 8
#define MAX_STEPS ROW*COL

//栈结构体
typedef struct stack {
    int x_adr;      //纵坐标
    int y_adr;      //横坐标
    int direction;  //方向
} HORSE_CHESS_STACK;

//存储路径棋盘
int chess[ROW + 1][COL + 1];

//下一步方向
//一号
int dir[8][2] = {{2,  -1},
                 {-2, -1},
                 {-2, 1},
                 {2,  1},
                 {1,  -2},
                 {-1, -2},
                 {-1, 2},
                 {1,  2}};

//二号
/* int dir[8][2] = {{1,2},{-1,-2},{-2,1},{2,1},
                  {2,-1},{1,-2},{-1,2},{-2,-1}}; */

//栈顶
int top;
HORSE_CHESS_STACK Adr_Stack[MAX_STEPS];

//出栈次数
int out_stack;

//初始化数据
void init() {
    int n = MAX_STEPS;
    while (n--) {
        Adr_Stack[n].x_adr = 0;
        Adr_Stack[n].y_adr = 0;
        Adr_Stack[n].direction = -1;
    }
    Adr_Stack[0].x_adr = 0;
    Adr_Stack[0].y_adr = 0;
    Adr_Stack[0].direction = -1;

    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= COL; j++) {
            chess[ROW][COL] = 0;
        }
    }

    top = -1;
    out_stack = 0;
}

//debug 打印栈的情况
void print_stack() {
    printf("栈的情况:\n");
    for (int i = 0; i < MAX_STEPS; i++) {
        printf("x:%d  y:%d direction = %d\n", Adr_Stack[i].y_adr, Adr_Stack[i].x_adr, Adr_Stack[i].direction);
    }
    printf("\n\n");
}

//入栈
void push_stack(int x_real, int y_real) {
    top++;
    Adr_Stack[top].x_adr = x_real;
    Adr_Stack[top].y_adr = y_real;
    Adr_Stack[top].direction = -1;  //初始化走的方向
}

//出栈
void pop_stack() {
    Adr_Stack[top].x_adr = 0;
    Adr_Stack[top].y_adr = 0;
    Adr_Stack[top].direction = -1;  //初始化走的方向
    top--;
}

//标记位置
void mark_chess(int x, int y) {
    chess[y][x] = top + 1;
}

//打印路径
void print_chess_board() {
    printf("\nroute:\n");
    for (int i = 1; i <= ROW; i++) {
        for (int j = 1; j <= ROW; j++) {
            printf("%4d ", chess[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//打印每一步的位置
int t = 1;

void print_steps() {
    printf("(%d,%d)", Adr_Stack[top].y_adr, Adr_Stack[top].x_adr);
    t++;
    if (t == ROW) {
        printf("\n");
        t = 0;
    }
}

//马踏棋盘（贪心）算法
void run_horse_tanxin() {
    int x_now, y_now;
    while (1) {

        //已经走完全图
        if (top >= MAX_STEPS - 1) {
            //打印棋盘
            print_chess_board();
            break;
        }

        //现在位置
        x_now = Adr_Stack[top].x_adr;
        y_now = Adr_Stack[top].y_adr;

        //对方向进行排序
        int next[ROW] = {};
        for (int i = 0; i < ROW; i++) {
            //下一步坐标
            int x_next = x_now + dir[i][0];
            int y_next = y_now + dir[i][1];

            if ((x_next > 0 && x_next <= COL) && (y_next > 0 && y_next <= ROW) && chess[y_next][x_next] == 0) {
                //对下一步的下一步判断是否可以走
                for (int j = 0; j < ROW; j++) {
                    int x_next_next = x_next + dir[j][0];
                    int y_next_next = y_next + dir[j][1];

                    //可以走,next 对应下标+1
                    if ((x_next_next > 0 && x_next_next <= COL) && (y_next_next > 0 && y_next_next <= ROW) &&
                        chess[y_next_next][x_next_next] == 0) {
                        next[i]++;
                    }
                }
            }
        }

        //依次返回 next 中最小元素的下标，返回后将元素赋值为最大
        int real_next[8] = {0};
        int k = 0;
        int t = ROW + 1;
        for (int i = 0; i < ROW; i++) {
            t = ROW + 1;
            for (int j = 0; j < 8; j++) {
                if (next[j] < t) {
                    real_next[i] = j;
                    t = next[j];
                    k = j;
                }
            }
            next[k] = ROW + 1;
        }

        //走下一步
        int dir_now = 0;
        for (dir_now = Adr_Stack[top].direction + 1; dir_now < ROW; dir_now++) {
            int x_real = x_now + dir[real_next[dir_now]][0];
            int y_real = y_now + dir[real_next[dir_now]][1];

            Adr_Stack[top].direction += 1;

            if ((x_real <= COL && x_real > 0) && (y_real <= ROW && y_real > 0) && chess[y_real][x_real] == 0) {
                //入栈
                push_stack(x_real, y_real);
                //标记棋盘
                mark_chess(x_real, y_real);
                break;
            }
        }

        //如果下一步走不了，则出栈回溯
        if (Adr_Stack[top].direction >= 7) {
            printf("\n out:(%d,%d) \n", Adr_Stack[top].y_adr, Adr_Stack[top].x_adr);
            chess[Adr_Stack[top].y_adr][Adr_Stack[top].x_adr] = 0;
            //记录出栈次数
            out_stack++;
            pop_stack();
        }

        //打印栈
        /* print_stack(); */
        //打印走了以后所处位置
        print_steps();
    }
}

int main() {
    int st_x, st_y;
    while (1) {
        printf("Please input: x  y :");
        scanf("%d %d", &st_x, &st_y);

        if (st_x > 0 && st_x <= ROW && st_y > 0 && st_y <= COL) {
            printf("Get x and y success!\n");
            break;
        }

        printf("Input wrong!please input x y again:");
    }
    init();
    /* print_stack(); */
    //获得开始时间
    clock_t start = clock();

    //将起始位置入栈
    push_stack(st_x, st_y);
    //标记起始位置
    mark_chess(st_x, st_y);

    printf("\nroute address:\n");
    printf("(%d,%d)", st_x, st_y);

    //开始算法
    run_horse_tanxin();

    //计算结束时间
    clock_t finish = clock();
    double run_time = (double) (finish - start) / CLOCKS_PER_SEC;

    printf("Running time：%f seconds  \nOut stack times:%d\n", run_time, out_stack);
}

#include <iostream>
using namespace std;

char cube[6][3][3];  // 위, 아래, 앞, 뒤, 왼, 오

void make_cube() {
    for (int k = 0; k < 6; k++) {
        switch (k) {
        case 0:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[0][i][j] = 'w';
                }
            }
            break;
        case 1:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[1][i][j] = 'y';
                }
            }
            break;
        case 2:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[2][i][j] = 'r';
                }
            }
            break;
        case 3:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[3][i][j] = 'o';
                }
            }
            break;
        case 4:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[4][i][j] = 'g';
                }
            }
            break;
        case 5:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cube[5][i][j] = 'b';
                }
            }
            break;
        }
    }
}

void plane_plus(int n) {
    char tmp1 = cube[n][0][0];
    char tmp2 = cube[n][0][1];
    char tmp3 = cube[n][0][2];

    cube[n][0][1] = cube[n][1][0];
    cube[n][0][0] = cube[n][2][0];

    cube[n][1][0] = cube[n][2][1];
    cube[n][2][0] = cube[n][2][2];

    cube[n][2][1] = cube[n][1][2];

    cube[n][0][2] = tmp1;
    cube[n][1][2] = tmp2;
    cube[n][2][2] = tmp3;
}

void plane_minus(int n) {
    char tmp1 = cube[n][0][0];
    char tmp2 = cube[n][0][1];
    char tmp3 = cube[n][0][2];

    cube[n][0][1] = cube[n][1][2];
    cube[n][0][2] = cube[n][2][2];

    cube[n][1][2] = cube[n][2][1];
    cube[n][2][2] = cube[n][2][0];

    cube[n][2][1] = cube[n][1][0];

    cube[n][0][0] = tmp3;
    cube[n][1][0] = tmp2;
    cube[n][2][0] = tmp1;
}

void rotate1(char dir) {  // 윗면 돌리기
    if (dir == '+') {
        char tmp1 = cube[2][0][0];
        char tmp2 = cube[2][0][1];
        char tmp3 = cube[2][0][2];

        // 오 -> 앞
        cube[2][0][0] = cube[5][0][0];
        cube[2][0][1] = cube[5][0][1];
        cube[2][0][2] = cube[5][0][2];

        // 뒤 -> 오
        cube[5][0][0] = cube[3][0][2];
        cube[5][0][1] = cube[3][0][1];
        cube[5][0][2] = cube[3][0][0];

        // 왼 -> 뒤
        cube[3][0][2] = cube[4][0][2];
        cube[3][0][1] = cube[4][0][1];
        cube[3][0][0] = cube[4][0][0];

        // 앞 -> 왼
        cube[4][0][2] = tmp1;
        cube[4][0][1] = tmp2;
        cube[4][0][0] = tmp3;

        plane_plus(0);
    }
    else {
        char tmp1 = cube[2][0][0];
        char tmp2 = cube[2][0][1];
        char tmp3 = cube[2][0][2];

        // 왼 -> 앞
        cube[2][0][0] = cube[4][0][2];
        cube[2][0][1] = cube[4][0][1];
        cube[2][0][2] = cube[4][0][0];

        // 뒤 -> 왼
        cube[4][0][2] = cube[3][0][2];
        cube[4][0][1] = cube[3][0][1];
        cube[4][0][0] = cube[3][0][0];

        // 오 -> 뒤
        cube[3][0][2] = cube[5][0][0];
        cube[3][0][1] = cube[5][0][1];
        cube[3][0][0] = cube[5][0][2];

        // 앞 -> 오
        cube[5][0][0] = tmp1;
        cube[5][0][1] = tmp2;
        cube[5][0][2] = tmp3;

        plane_minus(0);
    }
}

void rotate2(char dir) {  // 아랫면 돌리기
    if (dir == '+') {
        char tmp1 = cube[2][2][0];
        char tmp2 = cube[2][2][1];
        char tmp3 = cube[2][2][2];

        // 왼 -> 앞
        cube[2][2][0] = cube[4][2][2];
        cube[2][2][1] = cube[4][2][1];
        cube[2][2][2] = cube[4][2][0];

        // 뒤 -> 왼
        cube[4][2][2] = cube[3][2][2];
        cube[4][2][1] = cube[3][2][1];
        cube[4][2][0] = cube[3][2][0];

        // 오 -> 뒤
        cube[3][2][2] = cube[5][2][0];
        cube[3][2][1] = cube[5][2][1];
        cube[3][2][0] = cube[5][2][2];

        // 앞 -> 오
        cube[5][2][0] = tmp1;
        cube[5][2][1] = tmp2;
        cube[5][2][2] = tmp3;

        plane_minus(1);
    }
    else {
        char tmp1 = cube[2][2][0];
        char tmp2 = cube[2][2][1];
        char tmp3 = cube[2][2][2];

        // 오 -> 앞
        cube[2][2][0] = cube[5][2][0];
        cube[2][2][1] = cube[5][2][1];
        cube[2][2][2] = cube[5][2][2];

        // 뒤 -> 오
        cube[5][2][0] = cube[3][2][2];
        cube[5][2][1] = cube[3][2][1];
        cube[5][2][2] = cube[3][2][0];

        // 왼 -> 뒤
        cube[3][2][2] = cube[4][2][2];
        cube[3][2][1] = cube[4][2][1];
        cube[3][2][0] = cube[4][2][0];

        // 앞 -> 왼
        cube[4][2][2] = tmp1;
        cube[4][2][1] = tmp2;
        cube[4][2][0] = tmp3;

        plane_plus(1);
    }
}

void rotate3(char dir) {  // 앞면 돌리기
    if (dir == '+') {
        char tmp1 = cube[0][2][0];
        char tmp2 = cube[0][2][1];
        char tmp3 = cube[0][2][2];

        // 왼 -> 위
        cube[0][2][0] = cube[4][2][0];
        cube[0][2][1] = cube[4][1][0];
        cube[0][2][2] = cube[4][0][0];

        // 아래 -> 왼
        cube[4][2][0] = cube[1][2][2];
        cube[4][1][0] = cube[1][2][1];
        cube[4][0][0] = cube[1][2][0];

        // 오 -> 아래
        cube[1][2][2] = cube[5][0][0];
        cube[1][2][1] = cube[5][1][0];
        cube[1][2][0] = cube[5][2][0];

        // 위 -> 오
        cube[5][0][0] = tmp1;
        cube[5][1][0] = tmp2;
        cube[5][2][0] = tmp3;

        plane_plus(2);
    }
    else {
        char tmp1 = cube[0][2][0];
        char tmp2 = cube[0][2][1];
        char tmp3 = cube[0][2][2];

        // 오 -> 위
        cube[0][2][0] = cube[5][0][0];
        cube[0][2][1] = cube[5][1][0];
        cube[0][2][2] = cube[5][2][0];

        // 아래 -> 오
        cube[5][0][0] = cube[1][2][2];
        cube[5][1][0] = cube[1][2][1];
        cube[5][2][0] = cube[1][2][0];

        // 왼 -> 아래
        cube[1][2][2] = cube[4][2][0];
        cube[1][2][1] = cube[4][1][0];
        cube[1][2][0] = cube[4][0][0];

        // 위 -> 왼
        cube[4][2][0] = tmp1;
        cube[4][1][0] = tmp2;
        cube[4][0][0] = tmp3;

        plane_minus(2);
    }
}
void rotate4(char dir) {  // 뒷면 돌리기
    if (dir == '+') {
        char tmp1 = cube[0][0][2];
        char tmp2 = cube[0][0][1];
        char tmp3 = cube[0][0][0];

        // 오 -> 위
        cube[0][0][2] = cube[5][2][2];
        cube[0][0][1] = cube[5][1][2];
        cube[0][0][0] = cube[5][0][2];

        // 아래 -> 오
        cube[5][2][2] = cube[1][0][0];
        cube[5][1][2] = cube[1][0][1];
        cube[5][0][2] = cube[1][0][2];

        // 왼 -> 아래
        cube[1][0][0] = cube[4][0][2];
        cube[1][0][1] = cube[4][1][2];
        cube[1][0][2] = cube[4][2][2];

        // 위 -> 왼
        cube[4][0][2] = tmp1;
        cube[4][1][2] = tmp2;
        cube[4][2][2] = tmp3;

        plane_minus(3);
    }
    else {
        char tmp1 = cube[0][0][2];
        char tmp2 = cube[0][0][1];
        char tmp3 = cube[0][0][0];

        // 왼 -> 위
        cube[0][0][2] = cube[4][0][2];
        cube[0][0][1] = cube[4][1][2];
        cube[0][0][0] = cube[4][2][2];

        // 아래 -> 왼
        cube[4][0][2] = cube[1][0][0];
        cube[4][1][2] = cube[1][0][1];
        cube[4][2][2] = cube[1][0][2];

        // 오 -> 아래
        cube[1][0][0] = cube[5][2][2];
        cube[1][0][1] = cube[5][1][2];
        cube[1][0][2] = cube[5][0][2];

        // 위 -> 오
        cube[5][2][2] = tmp1;
        cube[5][1][2] = tmp2;
        cube[5][0][2] = tmp3;
        

        plane_plus(3);
    }
}
void rotate5(char dir) {  // 왼쪽면 돌리기
    if (dir == '+') {
        char tmp1 = cube[0][2][0];
        char tmp2 = cube[0][1][0];
        char tmp3 = cube[0][0][0];

        // 뒤 -> 위
        cube[0][2][0] = cube[3][0][0];
        cube[0][1][0] = cube[3][1][0];
        cube[0][0][0] = cube[3][2][0];

        // 아래 -> 뒤
        cube[3][0][0] = cube[1][0][0];
        cube[3][1][0] = cube[1][1][0];
        cube[3][2][0] = cube[1][2][0];

        // 앞 -> 아래
        cube[1][0][0] = cube[2][2][0];
        cube[1][1][0] = cube[2][1][0];
        cube[1][2][0] = cube[2][0][0];

        // 위 -> 앞
        cube[2][2][0] = tmp1;
        cube[2][1][0] = tmp2;
        cube[2][0][0] = tmp3;

        plane_minus(4);
    }
    else {
        char tmp1 = cube[0][2][0];
        char tmp2 = cube[0][1][0];
        char tmp3 = cube[0][0][0];

        // 앞 -> 위
        cube[0][2][0] = cube[2][2][0];
        cube[0][1][0] = cube[2][1][0];
        cube[0][0][0] = cube[2][0][0];

        // 아래 -> 앞
        cube[2][2][0] = cube[1][0][0];
        cube[2][1][0] = cube[1][1][0];
        cube[2][0][0] = cube[1][2][0];

        // 뒤 -> 아래
        cube[1][0][0] = cube[3][0][0];
        cube[1][1][0] = cube[3][1][0];
        cube[1][2][0] = cube[3][2][0];

        // 위 -> 뒤
        cube[3][0][0] = tmp1;
        cube[3][1][0] = tmp2;
        cube[3][2][0] = tmp3;

        plane_plus(4);
    }
}
void rotate6(char dir) {  // 오른쪽면 돌리기
    if (dir == '+') {
        char tmp1 = cube[0][2][2];
        char tmp2 = cube[0][1][2];
        char tmp3 = cube[0][0][2];

        // 앞 -> 위
        cube[0][2][2] = cube[2][2][2];
        cube[0][1][2] = cube[2][1][2];
        cube[0][0][2] = cube[2][0][2];

        // 아래 -> 앞
        cube[2][2][2] = cube[1][0][2];
        cube[2][1][2] = cube[1][1][2];
        cube[2][0][2] = cube[1][2][2];

        // 뒤 -> 아래
        cube[1][0][2] = cube[3][0][2];
        cube[1][1][2] = cube[3][1][2];
        cube[1][2][2] = cube[3][2][2];

        // 위 -> 뒤
        cube[3][0][2] = tmp1;
        cube[3][1][2] = tmp2;
        cube[3][2][2] = tmp3;

        plane_plus(5);
    }
    else {
        char tmp1 = cube[0][2][2];
        char tmp2 = cube[0][1][2];
        char tmp3 = cube[0][0][2];

        // 뒤 -> 위
        cube[0][2][2] = cube[3][0][2];
        cube[0][1][2] = cube[3][1][2];
        cube[0][0][2] = cube[3][2][2];

        // 아래 -> 뒤
        cube[3][0][2] = cube[1][0][2];
        cube[3][1][2] = cube[1][1][2];
        cube[3][2][2] = cube[1][2][2];

        // 앞 -> 아래
        cube[1][0][2] = cube[2][2][2];
        cube[1][1][2] = cube[2][1][2];
        cube[1][2][2] = cube[2][0][2];

        // 위 -> 앞
        cube[2][2][2] = tmp1;
        cube[2][1][2] = tmp2;
        cube[2][0][2] = tmp3;

        plane_minus(5);
    }
}

int main()
{
    int tc;
    cin >> tc;

    for (int t = 0; t < tc; t++) {
        make_cube();

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            switch (s[0]) {
            case 'U':
                rotate1(s[1]);
                break;
            case 'D':
                rotate2(s[1]);
                break;
            case 'F':
                rotate3(s[1]);
                break;
            case 'B':
                rotate4(s[1]);
                break;
            case 'L':
                rotate5(s[1]);
                break;
            case 'R':
                rotate6(s[1]);
                break;
            }
        }


        // 윗면의 색상 출력
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
    }
}

#include<stdio.h>
#include<conio.h>
int r,j,i,k,c;
void matrix_add(int a[r][c] , int b[r][c] , int m[r][c]){
    for(i=0;i<r;i++){
        for( j=0;j<c;j++){
        m[i][j]=a[i][j]+b[i][j];
        }
    }
}
void matrix_sub(int a[r][c] , int b[r][c] , int m[r][c]){
    for(i=0;i<r;i++){
        for( j=0;j<c;j++){
        m[i][j]=a[i][j]-b[i][j];
        }
    }
}
void transpose(int a[r][c] , int m[r][c]){
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            m[j][i]=a[i][j];
        }
    }
}
void multiplication(int a[r][c] , int b[r][c] , int m[r][c]){
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
        m[i][j]=0;
        for( k=0;k<c;k++){
            m[i][j]+=a[i][k] * b[k][j];
        }
    }

}

}
// void matrix_multiplication(int a[r][c], int b[r][c], int m[r][c]) {
//     for (i = 0; i < r; i++) {
//         for ( j = 0; j < c; j++) {
//             m[i][j] = 0;
//             for ( k = 0; k < c; k++) {
//                 m[i][j] += a[i][k] * b[k][j];
//             }
//         }
//     }
// }
void print_matrix(int M[][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    int a[r][c];
    int b[r][c];
    int m[r][c];

    printf("Enter matrix A:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter matrix B:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    matrix_add(a, b, m);

    printf("Result of matrix addition (A + B):\n");
    print_matrix(m);
     matrix_sub(a, b, m);

    printf("Result of matrix substraction (A - B):\n");
    print_matrix(m);
   multiplication(a,b,m);
   printf("result of multiplication of matrix a * b is:\n");
   print_matrix(m);

   transpose(a,m);
   printf("transpose of matrix a:\n");
   print_matrix(m);
   transpose(b,m);
   printf("transpose of matrix b\n");
   print_matrix(m);

  

    return 0;
}

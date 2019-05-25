#include <stdio.h>
#include <string.h>

#define MIN3(a,b,c) ((a)<(b)?((a)<(c)?(a):(c)):((b)<(c)?(b):(c)))

int cmp_levenshtein( const char *s1, const char *s2 );

int main( void )
{
    char str1[] = "Today is Saturday.";
    char str2[] = "Tomorrow is Sunday.";
    int d = cmp_levenshtein( str1, str2 );
    printf( "edit distance: %d\n", d );
    return 0;
}

int cmp_levenshtein( const char *s1, const char *s2 )
{
    int row = strlen(s1);               /* s1 的长度 */
    int col = strlen(s2);               /* s2 的长度 */

    int mat[row][col];                  /* C99 - variable-length array */

    for( int i=0; i<row; ++i ) {        /* 数组的行 */
        for( int j=0; j<col; ++j ) {    /* 数组的列 */
            if( i == 0 ) {
                mat[i][j] = j;          /* 初始化第1行为 [ 0 1 2 ... ] */
            }
            else if( j == 0 ) {
                mat[i][j] = i;          /* 初始化第1列为 [ 0 1 2 ... ] */
            }
            else {
                int cost = ( s1[i-1] == s2[j-1] ) ? 0 : 1;     /* 记录s1[i-1]与s2[j-1]是否相等 */
                mat[i][j] = MIN3( mat[i-1][j  ] + 1,           /* 取三者的最小值 */
                                  mat[i  ][j-1] + 1,
                                  mat[i-1][j-1] + cost);
            }
        }
    }

    return mat[row-1][col-1];
}

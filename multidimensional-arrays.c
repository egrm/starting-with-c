#include <stdio.h>

int main()
{
  int grades[2][5];

  grades[0][0] = 80;
  grades[0][1] = 70;
  grades[0][2] = 65;
  grades[0][3] = 89;
  grades[0][4] = 90;

  grades[1][0] = 85;
  grades[1][1] = 80;
  grades[1][2] = 80;
  grades[1][3] = 82;
  grades[1][4] = 87;

  int rows_count = 2;
  int columns_count = 5;

  for (int i = 0; i < rows_count; i++)
  {
    int average = 0;

    for (int j = 0; j < columns_count; j++)
    {
      average += grades[i][j];
    }

    average /= columns_count;

    printf("Average for the subject was %d\n", average);
  }


  return 0;
}

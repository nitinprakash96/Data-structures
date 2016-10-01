/**
 * Levenshtein Distance
 * The Levenshtein distance is a string metric for measuring the difference between two sequences.
 * Informally, the Levenshtein distance between two words is the minimum number of single-character edits
 * (i.e. insertions, deletions or substitutions) required to change one word into the other.
 * It is named after Vladimir Levenshtein, who considered this distance in 1965
 *
 * Example:
 *
 * The LD between "kitten" and "sitting" is 3,
 * since the following three edits change one into the other, and there is no way to do it with fewer than three edits:
 * kitten → sitten (substitution of "s" for "k")
 * sitten → sittin (substitution of "i" for "e")
 * sittin → sitting (insertion of "g" at the end).
 *
 * Following Programe uses Dynamic Programming to solve the problem.
 * Resources and Exampler Questions:
 * https://en.wikipedia.org/wiki/Levenshtein_distance
 * http://www.spoj.com/problems/EDIST/
 * https://www.codechef.com/problems/CF02
 *
 */


#include <stdio.h>
#include <algorithm>
using namespace std;

int smallest(int x, int y, int z){
    return min(x, min(y, z));
}

int LevenshteinDistance(char *source, char *target) {
  int source_len = strlen(source);
  int target_len = strlen(target);

  int dp[source_len+1][target_len+1];
  memset( dp, 0, (source_len+1)*(target_len+1)*sizeof(int) );
  int cost;

  int i, j;

  for (i = 1; i <= source_len; i++) dp[i][0] = i;
  for (i = 1; i <= target_len; i++) dp[i][0] = i;

  for (j = 1; j <= target_len; j++) {
    for (i = 1; i <= source_len; i++) {
      if(source[i-1] == target[j-1]) cost = 0;
      else cost = 1;

      dp[i][j] = smallest(dp[i-1][j]+1,
                     dp[i][j-1]+1,
                     dp[i-1][j-1]+cost);
    }
  }

  return dp[source_len][target_len];

}

int main() {
  char source[100], target[100];


  printf("Enter source string:-");
  scanf("%s", source);

  printf("Enter target string:-");
  scanf("%s", target);

  printf("Levenshtein Distance between source and target: %d\n", LevenshteinDistance(source, target));

  return 0;
}

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val t = reader.readLine().toInt()
    val ns = IntArray(t)
    var maxN = 0

    repeat(t) { i ->
        val n = reader.readLine().toInt()
        ns[i] = n
        if (n > maxN) maxN = n
    }

    val INF = Int.MAX_VALUE / 2
    val dp = IntArray(maxN + 1) { INF }
    dp[0] = 0

    for (i in 1..maxN) {
        dp[i] = minOf(dp[i], dp.getOrNull(i - 1)?.plus(1) ?: INF)
        if (i >= 3) {
            dp[i] = minOf(dp[i], dp[i - 3])
        }
        if (i >= 5) {
            dp[i] = minOf(dp[i], dp[i - 5])
        }
    }

    val output = StringBuilder()
    for (n in ns) {
        output.appendLine(dp[n])
    }

    print(output.toString())
}
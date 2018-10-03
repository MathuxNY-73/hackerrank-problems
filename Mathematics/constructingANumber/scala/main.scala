import java.io._
import java.math._
import java.security._
import java.text._
import java.util._
import java.util.concurrent._
import java.util.function._
import java.util.regex._
import java.util.stream._

object Solution {

    // Complete the canConstruct function below.
    def canConstruct(a: Array[Int]): String = {
        val rem = a.map(_%3).sum % 3
        if (rem == 0) "Yes" else "No"
    }

    def main(args: Array[String]) {
        val stdin = scala.io.StdIn

        val printWriter = new PrintWriter(sys.env("OUTPUT_PATH"))

        val t = stdin.readLine.trim.toInt

        for (tItr <- 1 to t) {
            val n = stdin.readLine.trim.toInt

            val a = stdin.readLine.split(" ").map(_.trim.toInt)
            val result = canConstruct(a)

            printWriter.println(result)
        }

        printWriter.close()
    }
}

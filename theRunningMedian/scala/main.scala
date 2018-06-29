import java.io.PrintWriter

object Solution {

    /*
     * Complete the runningMedian function below.
     */
    def runningMedian(a: Array[Int]): Array[Double] = {
        /*
         * Write your code here.
         */

    }

    def main(args: Array[String]) {
        val stdin = scala.io.StdIn

        val printWriter = new PrintWriter(sys.env("OUTPUT_PATH"))

        val aCount = stdin.readLine.trim.toInt

        val a = Array.ofDim[Int](aCount)

        for (aItr <- 0 until aCount) {
            val aItem = stdin.readLine.trim.toInt
            a(aItr) = aItem}

        val result = runningMedian(a)

        printWriter.println(result.mkString("\n"))

        printWriter.close()
    }
}

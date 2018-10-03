import java.io.PrintWriter

object Solution {

    /*
     * Complete the findPoint function below.
     */
    def findPoint(px: Int, py: Int, qx: Int, qy: Int): Array[Int] = Array(2*qx - px, 2*qy - py)

    def main(args: Array[String]) {
        val stdin = scala.io.StdIn

        val printWriter = new PrintWriter(System.out)

        val n = stdin.readLine.trim.toInt

        for (nItr <- 1 to n) {
            val pxPyQxQy = stdin.readLine.split(" ")

            val px = pxPyQxQy(0).trim.toInt

            val py = pxPyQxQy(1).trim.toInt

            val qx = pxPyQxQy(2).trim.toInt

            val qy = pxPyQxQy(3).trim.toInt

            val result = findPoint(px, py, qx, qy)

            printWriter.println(result.mkString(" "))
        }

        printWriter.close()
    }
}
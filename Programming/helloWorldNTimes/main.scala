import scala.language.implicitConversions
import scala.language.reflectiveCalls

object Solution {
    implicit def intWithTimes(n: Int) = new {
       def times(f: => Unit): Unit = 1 to n foreach { _ => f }
    }

    def f(n: Int): Unit = {
       n times { println("Hello World") }
    }

    def main(args: Array[String]) {
        var n = scala.io.StdIn.readInt
        f(n)
    }
}
object Solution {

    def f(delim:Int,arr:List[Int]):List[Int] = arr.filter(_ < delim)

    def main(args: Array[String]) {
        println(io.Source.stdin.getLines().take(2).map(_.toInt).sum)
    }
}
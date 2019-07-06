object Solution {

    def f(arr:List[Int]):List[Int] = arr.zipWithIndex.filter({case(_,i) => i % 2 == 1}).map(_._1)

    def main(args: Array[String]) {
        println(io.Source.stdin.getLines().take(2).map(_.toInt).sum)
    }
}
object Solution {

    def f(num: Int, arr: List[Int]): List[Int] = arr.flatMap(x => (1 to num).map(_ => x))

    def main(args: Array[String]): Unit = {
       f(5, [1,2,3,4])
    }
}
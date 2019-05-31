(defun sumOfOddElements (list &optional (acc 0))
  (if list
      (if (= (mod (car list) 2) 0)
          (sumOfOddElements (cdr list) acc)
          (sumOfOddElements (cdr list) (+ acc (car list))))
      acc
      )
  )

(prin1
 (sumOfOddElements
  (loop for line = (read-line *standard-input* nil)
        until (eq line nil)
        collect (parse-integer line)
        )
  )
)
(terpri)

(loop for x in
            (reverse
             (loop for line = (read-line *standard-input* nil)
                   until (eq line nil)
                   collect (parse-integer line))
             )
      do (prin1 x)
      do (terpri)
)

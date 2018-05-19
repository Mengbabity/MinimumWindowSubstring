# MinimumWindowSubstring

给定两个字符串，找出第二个字符串在第一个字符串中出现的最小子串。

例：S = "ADOBECODEBANC", T = "ABC"
   "BANC"
   
思路：首先定义一个长度为128的vector，因为字母的ASCII码值为65-122.
     将t中字母放入vector，个数为值，字母的ASCII码为下标。
     定义字符串s的两个指针begin和end，一个flag，以及最终返回的substr(head,min)。
     首先，若end在s中指向的字母为t中字母且个数>0，flag--，同时vector中的个数也--；
     若flag为零，说明已经找到了t中所有字母:
     1.这时，若end-begin<min，就将begin赋给head,将end-begin赋给min;
     2.若begin在s中指向的字母个数为零（vector中），说明是t中字母，因为在end走过之后其个数--，其他字母个数应为-1，因为也--过了；为零的，则个数++
     此时flag也++。表示begin过一个t中字母，end就需要向后遍历（像动态窗口），找到长度最小的为止。（小tip：当begin过，恢复其个数，再次向后滑动窗口时，
     找到相同字母，flag才会--，为零则比较长度）
     

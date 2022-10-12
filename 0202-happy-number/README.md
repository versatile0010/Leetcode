<h2><a href="https://leetcode.com/problems/happy-number/">202. Happy Number</a></h2><h3>Easy</h3><hr><div><p>Write an algorithm to determine if a number <code>n</code> is happy.</p>

<p>A <strong>happy number</strong> is a number defined by the following process:</p>

<ul>
	<li>Starting with any positive integer, replace the number by the sum of the squares of its digits.</li>
	<li>Repeat the process until the number equals 1 (where it will stay), or it <strong>loops endlessly in a cycle</strong> which does not include 1.</li>
	<li>Those numbers for which this process <strong>ends in 1</strong> are happy.</li>
</ul>

<p>Return <code>true</code> <em>if</em> <code>n</code> <em>is a happy number, and</em> <code>false</code> <em>if not</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 19
<strong>Output:</strong> true
<strong>Explanation:</strong>
1<sup>2</sup> + 9<sup>2</sup> = 82
8<sup>2</sup> + 2<sup>2</sup> = 68
6<sup>2</sup> + 8<sup>2</sup> = 100
1<sup>2</sup> + 0<sup>2</sup> + 0<sup>2</sup> = 1
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
</ul>
</div>

---
  정수 N 이 주어졌을 때, 각각의 자릿수에 대한 제곱의 합으로 N 을 업데이트하는 과정을 반복해서 수행할 때 N 이 결국에 1이 될 수 있다면 Happy number 라고 정의한다. 모든 입력되는 숫자가 happy number 이라면 쉽게 풀이가 가능하지만, 그렇지는 않다는 것이 문제이다. happy number 가 아닌 숫자가 들어오는 경우 아래와 같이 cycle 을 이루며 무한 루프에 빠져버릴 수 있다.  

  그러므로 happy number 인지 아닌지를 판단하는 과정 중에 해당 number 가 cycle 을 이루고 있지는 않은지 확인해야 한다. 

  또 생각할 수 있는 경우의 수는 무한대로 number 가 발산할 것인지이다. 생각해보면 들어올 수 있는 최대 숫자는 2147483647 이지만 각 자릿수의 제곱합은 260에 불과하다. 그러므로 절대로 무한대로 발산하지 않으므로, 최종적으로 고려해야 할 경우의 수는 happy number 인 경우(cycle 을 이루지 않음)와 happy number 가 아닌 경우(cycle 을 이루는 경우) 이다. 핵심은 cycle 의 유무 판별이다. 이를 위해 떠올릴 수 있는 풀이는 1. Hash table 을 이용한 방법과 2. Floyd's Cycle-Finding algorithm 이다. Hash table 을 이용한 방법은 간단하다. update 해야할 숫자를 계속 hash table 에 insert 하는데, 만약 다음으로 update 해야 할 숫자가 hash table 에 이미 존재한다면 cycle 을 이루는 것을 detect 할 수 있다. 코드는 아래와 같다. Vector 가 아닌 Hash table 을 사용하는 이유는 insert 와 put, find 가 O(1) 에 가능하기 때문이다.

  결국 서로 서로 연결된 Linked List(이하 연결리스트) 구조에서 cycle 을 detection 하는 것이 핵심이다. 위와 같이 Hash Set/Map 을 이용할 수도 있겠지만 Floyd's Cycle Detection Algorithm 을 사용하여 해결할 수도 있다. 이 알고리즘은 토끼와 거북이 알고리즘으로 기억하면 쉬운데, graph 에 토끼와 거북이를 진입시켜 달리게 했을 때 같은 노드에 도달하는 경우가 생기면 cycle 이 있는 거고 그렇지 않고 NULL 을 만나게 되는 경우 acyclic 하다는 것이다. 

  

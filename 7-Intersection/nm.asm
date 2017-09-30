Dump of assembler code for function intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&):
64	vector<int> intersection(const vector<int>&a, const vector<int>& b) {
   0x00401557 <+0>:	push   %ebp
   0x00401558 <+1>:	mov    %esp,%ebp
   0x0040155a <+3>:	push   %ebx
   0x0040155b <+4>:	sub    $0x44,%esp

65		std::vector<int> ret;
   0x0040155e <+7>:	mov    0x8(%ebp),%eax
   0x00401561 <+10>:	mov    %eax,(%esp)
   0x00401564 <+13>:	call   0x403334 <std::vector<int, std::allocator<int> >::vector()>

66		
67		std::vector<int>::const_iterator abegin = a.begin(), bbegin = b.begin();
   0x00401569 <+18>:	mov    0xc(%ebp),%eax
   0x0040156c <+21>:	mov    %eax,(%esp)
   0x0040156f <+24>:	call   0x4022cc <std::vector<int, std::allocator<int> >::begin() const>
   0x00401574 <+29>:	mov    %eax,-0x18(%ebp)
   0x00401577 <+32>:	mov    0x10(%ebp),%eax
   0x0040157a <+35>:	mov    %eax,(%esp)
   0x0040157d <+38>:	call   0x4022cc <std::vector<int, std::allocator<int> >::begin() const>
   0x00401582 <+43>:	mov    %eax,-0x1c(%ebp)

68		
69		while (abegin != a.end() and bbegin != b.end()) { // go through 2 arrays
   0x00401585 <+46>:	mov    $0x0,%ebx
   0x0040158a <+51>:	mov    0xc(%ebp),%eax
   0x0040158d <+54>:	mov    %eax,(%esp)
   0x00401590 <+57>:	call   0x402288 <std::vector<int, std::allocator<int> >::end() const>
   0x00401595 <+62>:	mov    %eax,-0x14(%ebp)
   0x00401598 <+65>:	movb   $0x1,-0x29(%ebp)
   0x0040159c <+69>:	lea    -0x14(%ebp),%eax
   0x0040159f <+72>:	mov    %eax,0x4(%esp)
   0x004015a3 <+76>:	lea    -0x18(%ebp),%eax
   0x004015a6 <+79>:	mov    %eax,(%esp)
   0x004015a9 <+82>:	call   0x40200c <__gnu_cxx::operator!=<int const*, std::vector<int, std::allocator<int> > >(__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > > const&, __gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > > const&)>
   0x004015ae <+87>:	test   %al,%al
   0x004015b0 <+89>:	je     0x4015e2 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+139>
   0x004015b2 <+91>:	mov    0x10(%ebp),%eax
   0x004015b5 <+94>:	mov    %eax,(%esp)
   0x004015b8 <+97>:	call   0x402288 <std::vector<int, std::allocator<int> >::end() const>
   0x004015bd <+102>:	mov    %eax,-0x10(%ebp)
   0x004015c0 <+105>:	mov    $0x1,%ebx
   0x004015c5 <+110>:	lea    -0x10(%ebp),%eax
   0x004015c8 <+113>:	mov    %eax,0x4(%esp)
   0x004015cc <+117>:	lea    -0x1c(%ebp),%eax
   0x004015cf <+120>:	mov    %eax,(%esp)
   0x004015d2 <+123>:	call   0x40200c <__gnu_cxx::operator!=<int const*, std::vector<int, std::allocator<int> > >(__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > > const&, __gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > > const&)>
   0x004015d7 <+128>:	test   %al,%al
   0x004015d9 <+130>:	je     0x4015e2 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+139>
   0x004015db <+132>:	mov    $0x1,%eax
   0x004015e0 <+137>:	jmp    0x4015e7 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+144>
   0x004015e2 <+139>:	mov    $0x0,%eax
   0x004015e7 <+144>:	test   %bl,%bl
   0x004015e9 <+146>:	cmpb   $0x0,-0x29(%ebp)
   0x004015ed <+150>:	test   %al,%al
   0x004015ef <+152>:	je     0x401711 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+442>
   0x004016f5 <+414>:	jmp    0x401585 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+46>
   0x004016fa <+419>:	mov    %eax,%ebx
   0x004016fc <+421>:	mov    0x8(%ebp),%eax
   0x004016ff <+424>:	mov    %eax,(%esp)
   0x00401702 <+427>:	call   0x403348 <std::vector<int, std::allocator<int> >::~vector()>
   0x00401707 <+432>:	mov    %ebx,%eax
   0x00401709 <+434>:	mov    %eax,(%esp)
   0x0040170c <+437>:	call   0x401828 <_Unwind_Resume>

70			if (*abegin == *bbegin) {
   0x004015f5 <+158>:	lea    -0x18(%ebp),%eax
   0x004015f8 <+161>:	mov    %eax,(%esp)
   0x004015fb <+164>:	call   0x402078 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x00401600 <+169>:	mov    (%eax),%ebx
   0x00401602 <+171>:	lea    -0x1c(%ebp),%eax
   0x00401605 <+174>:	mov    %eax,(%esp)
   0x00401608 <+177>:	call   0x402078 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x0040160d <+182>:	mov    (%eax),%eax
   0x0040160f <+184>:	cmp    %eax,%ebx
   0x00401611 <+186>:	sete   %al
   0x00401614 <+189>:	test   %al,%al
   0x00401616 <+191>:	je     0x4016ac <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+341>

71				// if (!(ret.size() >= 1 and *abegin == *ret.rbegin())) // checks already created list for duplicates https://en.wikipedia.org/wiki/Short-circuit_evaluation
72				if (ret.size() == 0 or *abegin != *ret.rbegin()) // demorgans law -- makes things more efficient
   0x0040161c <+197>:	movb   $0x0,-0x29(%ebp)
   0x00401620 <+201>:	mov    0x8(%ebp),%eax
   0x00401623 <+204>:	mov    %eax,(%esp)
   0x00401626 <+207>:	call   0x4022b0 <std::vector<int, std::allocator<int> >::size() const>
   0x0040162b <+212>:	test   %eax,%eax
   0x0040162d <+214>:	je     0x401666 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+271>
   0x0040162f <+216>:	lea    -0x18(%ebp),%eax
   0x00401632 <+219>:	mov    %eax,(%esp)
   0x00401635 <+222>:	call   0x402078 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x0040163a <+227>:	mov    (%eax),%ebx
   0x0040163c <+229>:	lea    -0xc(%ebp),%eax
   0x0040163f <+232>:	mov    0x8(%ebp),%edx
   0x00401642 <+235>:	mov    %edx,0x4(%esp)
   0x00401646 <+239>:	mov    %eax,(%esp)
   0x00401649 <+242>:	call   0x403178 <std::vector<int, std::allocator<int> >::rbegin()>
   0x0040164e <+247>:	sub    $0x4,%esp
   0x00401651 <+250>:	movb   $0x1,-0x29(%ebp)
   0x00401655 <+254>:	lea    -0xc(%ebp),%eax
   0x00401658 <+257>:	mov    %eax,(%esp)
   0x0040165b <+260>:	call   0x40217c <std::reverse_iterator<__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > > >::operator*() const>
   0x00401660 <+265>:	mov    (%eax),%eax
   0x00401662 <+267>:	cmp    %eax,%ebx
   0x00401664 <+269>:	je     0x40166d <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+278>
   0x00401666 <+271>:	mov    $0x1,%eax
   0x0040166b <+276>:	jmp    0x401672 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+283>
   0x0040166d <+278>:	mov    $0x0,%eax
   0x00401672 <+283>:	cmpb   $0x0,-0x29(%ebp)
   0x00401676 <+287>:	test   %al,%al
   0x00401678 <+289>:	je     0x401694 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+317>

73					ret.push_back(*abegin); // not found in either array or in already created array
   0x0040167a <+291>:	lea    -0x18(%ebp),%eax
   0x0040167d <+294>:	mov    %eax,(%esp)
   0x00401680 <+297>:	call   0x402078 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x00401685 <+302>:	mov    %eax,0x4(%esp)
   0x00401689 <+306>:	mov    0x8(%ebp),%eax
   0x0040168c <+309>:	mov    %eax,(%esp)
   0x0040168f <+312>:	call   0x4032dc <std::vector<int, std::allocator<int> >::push_back(int const&)>

74				++abegin;
   0x00401694 <+317>:	lea    -0x18(%ebp),%eax
   0x00401697 <+320>:	mov    %eax,(%esp)
   0x0040169a <+323>:	call   0x401f14 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator++()>

75				++bbegin; // increment both cause oth points to the same value
   0x0040169f <+328>:	lea    -0x1c(%ebp),%eax
   0x004016a2 <+331>:	mov    %eax,(%esp)
   0x004016a5 <+334>:	call   0x401f14 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator++()>

76				continue;
   0x004016aa <+339>:	jmp    0x4016f5 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+414>

77			}
78			
79			(*abegin < *bbegin)? abegin++ : bbegin++; // different values, increment lesser one
   0x004016ac <+341>:	lea    -0x18(%ebp),%eax
   0x004016af <+344>:	mov    %eax,(%esp)
   0x004016b2 <+347>:	call   0x402078 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x004016b7 <+352>:	mov    (%eax),%ebx
   0x004016b9 <+354>:	lea    -0x1c(%ebp),%eax
   0x004016bc <+357>:	mov    %eax,(%esp)
   0x004016bf <+360>:	call   0x402078 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator*() const>
   0x004016c4 <+365>:	mov    (%eax),%eax
   0x004016c6 <+367>:	cmp    %eax,%ebx
   0x004016c8 <+369>:	jge    0x4016e2 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+395>
   0x004016ca <+371>:	movl   $0x0,0x4(%esp)
   0x004016d2 <+379>:	lea    -0x18(%ebp),%eax
   0x004016d5 <+382>:	mov    %eax,(%esp)
   0x004016d8 <+385>:	call   0x401ee4 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator++(int)>
   0x004016dd <+390>:	jmp    0x401585 <intersection(std::vector<int, std::allocator<int> > const&, std::vector<int, std::allocator<int> > const&)+46>
   0x004016e2 <+395>:	movl   $0x0,0x4(%esp)
   0x004016ea <+403>:	lea    -0x1c(%ebp),%eax
   0x004016ed <+406>:	mov    %eax,(%esp)
   0x004016f0 <+409>:	call   0x401ee4 <__gnu_cxx::__normal_iterator<int const*, std::vector<int, std::allocator<int> > >::operator++(int)>

80		}
81		
82		return ret;
   0x00401711 <+442>:	nop

83	}   0x00401712 <+443>:	mov    0x8(%ebp),%eax
   0x00401715 <+446>:	mov    -0x4(%ebp),%ebx
   0x00401718 <+449>:	leave  
   0x00401719 <+450>:	ret    $0x4

End of assembler dump.

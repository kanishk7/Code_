%Transition matrix M 

M = [0.8 0.25; 0.2 0.75]

initial = [0 1]
size(initial)
size(a(1))
a = ones(100,2);
a(1,:) = initial;

for i = 2:100
	a(i,:) = M*a((i-1),:)';
end

a
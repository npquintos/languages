If you have something like

      int i = 6;
      int *pi = &i;
  
You could change i via pi as follows:

      *pi = 10;    // i is now 10 as well;
  
You could also make pi point to another integer as well:

      int j = 11;
      pi = &j;

What if, you want pi to always point to i and not point it to anywhere else? The declaration should now be:

  int i = 6;
  int *const pi = &i;   // pi is now a const; you cannot point it anywhere else
  int j = 11;
  pi = &j;  // error, pi is const

What if, you don't want to be able to change the value via the pi pointer?

  int i = 6;
  const int *pi = &i;
  *pi = 10;  // error, *pi is const
  pi = &j;   // still ok, you could point pi anywhere; it is the contents that you could not change

What if, you don't want to be able to change the value that it points to, and where it points to?

  int i = 6;
  int j = 11;
  const int *const pi = &i;
  pi = &j;     // error; pi is permanently assigned to &i because of 'const pi'
  *pi = 100;   // error; *pi cannot be changed because of 'const int *pi'

In summary:

  const int *const pi = &i;
     ^         ^   
     |         + ---- makes pi a const - i.e. - you cannot reassign pi value ---> pi = &j; // error; pi is permanently pointing to i and you are reassigning it to j
     + -------------- makes *pi a const - i.e. - you cannot change value of *pi
     
A good way to remember this is:

  const int i ----> i is a const and could not be changed
  const int *j ----> *j is a const and could not be changed; however, you could still change the value of j as j is not a const



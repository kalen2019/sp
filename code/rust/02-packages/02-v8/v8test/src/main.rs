fn main() {
    // println!("Hello, world!");
    use v8::{self, value};

    // Create a V8 heap
    let isolate = v8::Isolate::new();
    // Create a new context of execution
    let context = v8::Context::new(&isolate);
    
    // Load the source code that we want to evaluate
    let source = value::String::from_str(&isolate, "'Hello, ' + 'World!'");
    
    // Compile the source code.  `unwrap()` panics if the code is invalid,
    // e.g. if there is a syntax  error.
    let script = v8::Script::compile(&isolate, &context, &source).unwrap();
    
    // Run the compiled script.  `unwrap()` panics if the code threw an
    // exception.
    let result = script.run(&context).unwrap();
    
    // Convert the result to a value::String.
    let result_str = result.to_string(&context);
    
    // Success!
    assert_eq!("Hello, World!", result_str.value());
}

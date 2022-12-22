use lib::{recursive_size};
use std::env;

fn main(){
    
    //print_type_of(env::current_dir());
    let lines = recursive_size(env::current_dir().unwrap());
    for line in lines
    {
        //println!("Dir {} Size = {}", line.0.to_str().unwrap(), line.1);
    }
    
}


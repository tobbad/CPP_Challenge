use lib::{recursive_size};
use std::env;

fn main(){
    
    
    let lines = recursive_size(env::current_dir());
    for line in lines
    {
        println!("{}", line);
    }
    
}


use lib::{recursive_size};
use std::env;

fn main(){
    
    let root = env::current_dir().unwrap();
    let res = recursive_size(root);
    for (k,v) in res
    {
        println!("{:?} {}", k, v);
    }

    
}


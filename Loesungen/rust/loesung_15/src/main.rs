use network::{IPV4};
use lib::{string_to_u8_vec};

fn main(){
    let ps  = String:from("1,2,4,9"); // This is a String
    let ipa = string_to_u8_vec(ps);
    let ip = IPV4{
        ip: ipa,
    };
    println!("{:?}", ip);

}


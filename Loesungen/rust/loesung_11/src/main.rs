use loesung_11::{to_roman, get_int_fromcl};

fn main(){
	let mut number = get_int_fromcl(&String::from("Upper limit? "));
	let res = to_roman(number);
	println!("{}", res);
}

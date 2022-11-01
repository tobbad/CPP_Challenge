use lib::{print_amicables,get_int_fromcl};

fn main(){
	let limit = get_int_fromcl(&String::from("Upper limit? "));
	print_amicables(limit);
}

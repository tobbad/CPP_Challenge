use lib::{Matrix};

fn main(){
    let mut  a = Matrix::new(3,2);
    println!("{}",a );
    //println!("{:?}", a);
    //println!("{}", a);
    let v = [1,2,3,4,5,6];
    a.set(&v);
    let mut  b = Matrix::new(3,2);
    println!("{}", a);
    println!("{}", b);
    a.swap(&mut b);
    println!("{}", a);
    println!("{}", b);
    b.fill(-1);
    println!("{}", b);
   
    

}


// use std::cmp::Ordering;
use std::collections::BinaryHeap;
use std::io::stdin;

fn main() {
    println!("Hello, world!");
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    // let s = "27".to_string();

    let mut pq: BinaryHeap<i32> = BinaryHeap::new();

    let n: i32 = s.trim().parse().unwrap();

    for i in 0..n {
        println!("i: {i}");
        let mut curr_string = String::new();
        stdin().read_line(&mut curr_string).unwrap();
        let val: i32 = curr_string.trim().parse().unwrap();
        pq.push(val);
    }

    while let Some(curr_val) = pq.pop() {
        println!("{curr_val}");
        println!("Hello!");
    }
}

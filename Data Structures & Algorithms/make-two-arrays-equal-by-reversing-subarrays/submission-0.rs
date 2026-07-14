use std::collections::HashMap;

impl Solution {
pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
    let mut t_map: HashMap<i32, u32> = HashMap::with_capacity(target.len()/2);
    let mut a_map: HashMap<i32, u32> = HashMap::with_capacity(target.len()/2);

    for i in 0..target.len() {
        if a_map.contains_key(&arr[i]) {
            *a_map.get_mut(&arr[i]).unwrap() += 1;
        } else {
            a_map.insert(arr[i], 1);
        }

        if t_map.contains_key(&target[i]) {
            *t_map.get_mut(&target[i]).unwrap() += 1;
        } else {
            t_map.insert(target[i], 1);
        }
    }

    if t_map == a_map {
        true
    } else {
        false
    }
}


}

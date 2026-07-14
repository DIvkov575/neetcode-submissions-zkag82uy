impl Solution {
    pub fn number_to_words(num: i32) -> String {
        if num != 0 {
            let mut a = (match_billions(num) + &match_millions(num) + &match_thousands(num) + &match_all_hunds(num%1000));
            if a.get((a.len()-1)..a.len()).unwrap() == " " {
                a.pop();
            };
            for idx in (0..(a.len()-1)).rev() {
                println!("{}", idx);
                if a[idx..=idx] == *" " && a[idx..=idx] == a[(idx+1)..=(idx+1)] {
                    a.remove(idx);
                };
            };
            return a;
        } else {
            "Zero".to_string()
        }
    }
}


fn match_billions(num:i32) -> String {
    let a = num/1_000_000_000;
    if a != 0 {
        match_ones(a) + " Billion "
    } else {
        "".to_string()
    }
}


fn match_millions(num: i32) -> String {
    let a = num/1_000_000%1000;
    if a != 0 {
        match_all_hunds(a) + " Million "
    } else {
        "".to_string()
    }
}
fn match_thousands(num: i32) -> String {
    let a = num/1000%1000;
    if a != 0 {
        match_all_hunds(a) + " Thousand "
    } else {
        "".to_string()
    }
}

fn match_ones(a: i32) -> String {
    println!("a: {}", a);
    match a {
        0 => "",
        1 => "One",
        2 => "Two",
        3 => "Three",
        4 => "Four",
        5 => "Five",
        6 => "Six",
        7 => "Seven",
        8 => "Eight",
        9 => "Nine",
        _ => unreachable!(),
    }.to_owned()
}

fn match_all_hunds(a:i32) -> String {
    assert_eq!(a, a%1000);
    println!("b: {}", a);

    let hundreds = {
        if a/100 != 0 {
            match_ones(a/100) + " Hundred "
        } else {
            "".to_string()
        }
    };


    let tens_ones= match a/10%10 {
        0 => {
            match_ones(a%10)
        }
        1 => {
            match a%20 {
                10 => "Ten",
                11 => "Eleven",
                12 => "Twelve",
                13 => "Thirteen",
                14 => "Fourteen",
                15 => "Fifteen",
                16 => "Sixteen",
                17 => "Seventeen",
                18 => "Eighteen",
                19 => "Nineteen",
                _ => unreachable!(),
            }.to_string()
        }
        2 => { "Twenty ".to_string() + &match_ones(a%10)},
        3 => { "Thirty ".to_string() + &match_ones(a%10)},
        4 => { "Forty ".to_string() + &match_ones(a%10)},
        5 => { "Fifty ".to_string() + &match_ones(a%10)},
        6 => { "Sixty ".to_string() + &match_ones(a%10)},
        7 => { "Seventy ".to_string() + &match_ones(a%10)},
        8 => { "Eighty ".to_string() + &match_ones(a%10)},
        9 => { "Ninety ".to_string() + &match_ones(a%10)},
        _ => unreachable!(),
    }.to_string();


    hundreds + &tens_ones
}

#!/bin/bash

Address_book="Address_book.txt"		#no space between =

create_address_book(){
	touch "$Address_book"
	echo "Address book created successfully !!";
}

view_add_book(){
	if [ -s "$Address_book" ]; then
		echo -e "\nAddress Book"
		cat "$Address_book"
	else
		echo "Address book is empty !!"
	fi
}

insert_in_book(){
	echo "Enter the details : "
	echo -e "\nEnter name : "
	read name
	echo "Enter mobile no : "
	read mob
	echo "Enter email id : "
	read email
	
	echo "$name: $mob, $email" >> "$Address_book"
	echo "Data entered successfully!!"
}

delete_record(){
	echo "Enter the name for which record to be deleted : "
	read name
	sed -i "/^$name:/d" "$Address_book"
	if [ $? -eq 0 ];then
		echo "Data deleted successfully"
	else
		echo "Data not found"
	fi
}

modify_record(){

    echo "Enter name to moodiy record: "
    read name

    if grep -q "^$name:" "$Address_book"; then
        echo "Enter Phone Details to update: "
        read pno
        echo "Enter Email to update: "
        read email

        sed -i "/^$name:/c\\$name: $pno, $email" "$Address_book"
        echo "Data modified for $name!!!"
    else
        echo "Name is not present in Database"
    fi 
}


#main menu
while true;
do
	echo -e "\nOptions:"
	echo "1.Create Address Book"
	echo "2.View Address Book"
	echo "3.Insert in Address Book"
	echo "4.Modify record in Address Book"
	echo "5.Delete a record in Address Book"
	echo "6.Exit"
	
	read -p "Select the Option(1/2/3/4/5/6):" option
	
	case $option in
		1)create_address_book ;; 
		2)view_add_book ;;
		3)insert_in_book ;;
		4)modify_record ;;
		5)delete_record ;;
		6)exit 0 ;;
		*)echo "Enter valid option"
	esac
done




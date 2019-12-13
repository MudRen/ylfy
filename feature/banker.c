
int pay_player(object who, int amount)
{
    object ob;
        if (!(ob = find_object(GOLD_OB))) ob=load_object(GOLD_OB);
        if (!(ob = find_object(SILVER_OB))) ob=load_object(SILVER_OB);
        if (!(ob = find_object(COIN_OB))) ob=load_object(COIN_OB);
    if( amount < 1 ) amount = 1;
        if( amount/10000 ) {
        if (!ob=present("gold_money", who)){
                    ob = new(GOLD_OB);
            if ( !ob->move(who) ){
                ob->set_amount(amount/10000);
                ob->move(environment(who));
            }else   ob->set_amount(amount/10000);
        }else   ob->add_amount(amount/10000);
        amount %= 10000;
    }
    if( amount/100 ) {
        if (!ob=present("silver_money", who)){
                    ob = new(SILVER_OB);
            if (!ob->move(who)){
                ob->set_amount(amount/100);
                ob->move(environment(who));
            }else   ob->set_amount(amount/100);
        }else   ob->add_amount(amount/100);
        amount %= 100;
    }
    if( amount ) {
        if (!ob=present("coin_money", who)){
            ob = new(COIN_OB);
            if (!ob->move(who)){
                ob->set_amount(amount);
                ob->move(environment(who));
            }else   ob->set_amount(amount);
        }else   ob->add_amount(amount);
    }
    return 1;
}
string value_string(int value1,int value)
{
    string str;
    if (value1){
        str=((int)(value1/10000)?chinese_number(value1/10000)+"��":"") +chinese_number(value1%10000)+ "��";
    if( value < 1 ) return str+"���ƽ�";
    else    if( value < 100 )
        return str +"���ƽ�"+ chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return str +"���ƽ�"+chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return str + chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
    }else   {
    if( value < 1 ) return "";
    else    if( value < 100 )
        return chinese_number(value) + "��Ǯ";
    else    if( value < 10000 )
        return chinese_number(value/100) + "������"
            + (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
    else
        return chinese_number(value/10000) + "���ƽ�"
            +( (value%10000)/100 ? chinese_number((value%10000)/100) + "������" : "")
            +( (value%10000)%100 ? "��" + chinese_number((value%10000)%100) + "��Ǯ": "");
    }
}
int do_convert(string arg)
{
    string from, to;
    int amount, bv1, bv2,total;
    object from_ob, to_ob;
    
	if ( !arg || sscanf(arg, "%d %s to %s", amount, from, to) != 3 )
        return notify_fail("ָ���ʽ��convert <����> <��������> to <��������>\n");
    
	from_ob = present(from + "_money", this_player());
    to_ob = present(to + "_money", this_player());
    
	if ( file_size("/clone/money/" + to + ".c") < 0 && file_size("/binaries/clone/money/" + to + ".b") < 0 )
        return notify_fail("����һ���һ��Ǯ��\n");

	//��δ֪�ļ�con.c���жϣ�����Debug.
	if ( to == "con" )
		return notify_fail("����һ���һ��Ǯ��\n");
    if ( !from_ob )
        return notify_fail("������û�����ֻ��ҡ�\n");   
	if ( amount < 1 )
        return notify_fail("�һ�����һ������Ҫ�һ�һ����\n");       
    if ( (total= (int)from_ob->query_amount()) < amount )
        return notify_fail("������û�������" + from_ob->query("name") + "��\n");
   
	bv1 = from_ob->query("base_value");
    
	if( !bv1 )
		return notify_fail("���ֶ�����ֵǮ��\n");
    
	bv2 = to_ob ? to_ob->query("base_value") : call_other("/clone/money/" + to, "query", "base_value" );
    
	if ( bv1 == bv2 )
		return notify_fail("�����Ĳ����İ���\n");
    if ( bv1 > 1000000 && amount > 100 )
		amount=100;
    if( bv1 < bv2 )
		amount -= amount % (bv2 / bv1);
    if( amount==0 ) 
		return notify_fail("��Щ" + from_ob->query("name") + "�ļ�ֵ̫���ˣ�������\n");
    
	if ((amount * bv1 / bv2)>100000 || (amount * bv1 / bv2)<0)  
		return notify_fail("��ׯ���ֲ��㣬��������ô��Ǯ��\n");
	
	if ( !(to_ob = find_object("/clone/money/" + to)) )
		to_ob = load_object("/clone/money/" + to);
	
	to_ob = new("/clone/money/" + to);
	to_ob->set_amount(amount * bv1 / bv2);
	
	if ( !to_ob->move(this_player()) )
	{
		to_ob->move(VOID_OB);
		destruct(to_ob);
	}

	if ( to_ob )
	{
		message_vision( sprintf("$N������ȡ��%s%s%s������%s%s%s��\n",
			chinese_number(amount), from_ob->query("base_unit"), from_ob->query("name"),
			chinese_number(amount * bv1 / bv2), to_ob->query("base_unit"), to_ob->query("name")),
			this_player() );
	}

	from=base_name(from_ob);
    destruct(from_ob);
    
	if ( total-amount > 0 )
	{
        from_ob=new(from);
        from_ob->set_amount(total-amount);
        from_ob->move(this_player());
    }

    return 1;
}
// ��Ǯ
int do_deposit(string arg)
{
    string money;
    int amount,value,i,total;
    object money_ob;
    if( !arg)
        return notify_fail("ָ���ʽ��deposit <����>||all <��������>\n");
    if ( sscanf(arg, "%d %s", amount, money)!=2 )
        if (sscanf(arg, "all %s", money)!=1 )
        return notify_fail("ָ���ʽ��deposit <����>||all <��������>\n");
    money_ob = present(money + "_money", this_player());
    if( !money_ob)
        return notify_fail("������û�����֡�Ǯ����\n");
    if (!amount)    amount=money_ob->query_amount();
    if( amount < 1 )    return notify_fail("���١�����Ҫ��һ���Ӱɣ�\n");
    if (money_ob->query("base_value")>10000 && amount>100){
        tell_object(this_player(),"һ�����ֻ�ܴ�һ����"+money_ob->query("name")+"��\n");
        amount=100;
    }
    if((total=(int)money_ob->query_amount()) < amount )
        return notify_fail("������û��������" + money_ob->query("name") + "��\n");
    message_vision( sprintf("$N������ȡ��%s%s%s������Ǯׯ��\n",
        chinese_number(amount), money_ob->query("base_unit"), money_ob->query("name")),
        this_player() );
    if (money_ob->query("base_value")>10000){
        reset_eval_cost();
        for (i=0;i<amount;i++){
            value=money_ob->query("base_value")+this_player()->query("money");
            this_player()->add("more_money",value/100000000);
            this_player()->set("money",value%100000000);
        }
    }else{
        value=amount*money_ob->query("base_value")+this_player()->query("money");
        this_player()->add("more_money",value/100000000);
        this_player()->set("money",value%100000000);
    }
    money=base_name(money_ob);
    destruct(money_ob);
    if (total-amount>0){
        money_ob=new(money);
        if (!money_ob->move(this_player())){
            money_ob->set_amount(total-amount);
            money_ob->move(environment(this_player()));
        }else   money_ob->set_amount(total-amount);
    }
    return 1;
}
int do_withdraw(string arg)
{
    string money;
    int amount,value_money;
    object money_ob;
	
    if( !arg || sscanf(arg, "%d %s", amount, money)!=2 )
        return notify_fail("ָ���ʽ��withdraw <����> <��������>\n");
	if ( money == "con" )
		return notify_fail("��ֻ��ȡ��Ǯ����\n");
    if (file_size("/clone/money/" + money + ".c") < 0)
        return notify_fail("��ֻ��ȡ��Ǯ����\n");
    money_ob = new("/clone/money/"+money);
    if (money_ob->query("base_value")>10000)
        return notify_fail("��ֻ��ȡ�ƽ����ӻ�ͭ�壡\n");
    if( amount < 1 )    return notify_fail("���١�����Ҫȡһ���Ӱɣ�\n");
    value_money=amount*money_ob->query("base_value");
    if (value_money<100) return notify_fail("����Ҫȡһ�ٸ�ͭ�壡\n");
    if (value_money>20000000)
        return notify_fail("ȡ��ô��Ǯ���㲻�±����ô��\n");
    if (value_money*101/100 >this_player()->query("money") && this_player()->query("more_money")<1)
            return notify_fail("��û����ô���\n");
    message_vision( sprintf("$N��Ǯׯȡ��%s��\n",
    value_string((value_money)/100000000,(value_money)%100000000)),
        this_player() );
    pay_player(this_player(), value_money);
    
    if (value_money>this_player()->query("money")){
        this_player()->add("more_money",-1);
        this_player()->add("money",100000000-value_money/100*101);
    }
    else
    this_player()->add("money",-value_money/100*101);
    return 1;
}

object find_player(string target)
{
    int i;
    object *str;
    str=users();
    for (i=0;i<sizeof(str);i++)
        if (str[i]->query("id")==target)
            return str[i];
    return 0;
}
int do_check(string arg)
{
    object ob,me;
    me=this_player();
    if (arg){
        if( wizardp(me)) {
            ob = find_player(arg);
            if( !ob ) ob = find_living(arg);
            if( !ob ) ob = present(arg, environment(me));
        }else   return 0;
    }
    if (!objectp(ob))   ob=this_player();
    if (ob->query("money") || ob->query("more_money")){
      if (ob->query("more_money")>5000) ob->set("more_money",5000); //��������Ϊ5000��ԭ500
        tell_object(me , sprintf(this_object()->name()+"���ĵĸ����㣬%s�ڱ�ׯ������%s��\n",
            ob==me?"��":ob->query("name"),
            value_string(ob->query("more_money"),ob->query("money")) ) );
    }   else
        tell_object(me , sprintf("%sû���κδ�\n",ob==me?"��":ob->query("name")));
        return 1;
}

int get_biaoshi(string biaoshi,object me,int gold,string username)
{
    string old_biaoshi;
    int mygold;
    int usergold;
    int maxgold;
    int mycoin;
    int usercoin;
    object user = find_player(username);
    object ob = me->query_temp("link_ob");
    if(!ob)
    {
	tell_object(me,"�����������\n");
	user->delete_temp("doing_transfer");
	me->delete_temp("doing_transfer");
	return 1;
    }
    if(!user || !userp(user))
    {
	tell_object(me,"�Է��Ѿ����ߡ�\n");
	me->delete_temp("doing_transfer");
	return 1;
    }
while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
    old_biaoshi=ob->query("biaoshiold");
    if( crypt(biaoshi, old_biaoshi)!=old_biaoshi ) 
    {
	tell_object(me,"��ݱ�ʶ����\n");
	user->delete_temp("doing_transfer");
	me->delete_temp("doing_transfer");
	return 0;
    }
    usergold = user->query("more_money")*10000 + user->query("money")/10000;
    maxgold = 50000000 - usergold;
    if(maxgold <= 0)
    {
	tell_object(me,"�Է��˻����������\n");
	user->delete_temp("doing_transfer");
	me->delete_temp("doing_transfer");
	return 1;
    }
    if(maxgold > gold)
	maxgold = gold;

    mycoin=me->query("money")%10000;
    usercoin=user->query("money")%10000;

    mygold = me->query("more_money")*10000 + me->query("money")/10000;
    if(mygold < maxgold)
    {
	user->delete_temp("doing_transfer");
	me->delete_temp("doing_transfer");
	tell_object(me,"���Ǯׯ��û��ô��Ǯ��\n");
	return 1;
    }

    mygold -= maxgold;
    usergold += maxgold;
    me->set("more_money",mygold/10000);
    me->set("money",(mygold%10000)*10000+mycoin);
    user->set("more_money",usergold/10000);
    user->set("money",(usergold%10000)*10000+usercoin);
    me->save();
    user->save();
    tell_object(me,"��ɹ���"HIG+user->query("name")+"("+user->query("id")+")"NOR+"���˻�ת��"HIW+chinese_number(maxgold)+NOR"���ƽ�\n");
    tell_object(user,HIR+me->query("name")+"("+me->query("id")+")������˻�ת��"+chinese_number(maxgold)+"���ƽ�\n"NOR);
    user->delete_temp("doing_transfer");
    me->delete_temp("doing_transfer");
    return 1;
}

int do_transfer(string arg)
{
    object me,user;
    string username;
    int gold,mygold;
    me = this_player();
    if(!arg || sscanf(arg,"%d to %s",gold,username) != 2)
    {
	tell_object(me,"ʹ�÷�����zhuan <�ƽ�����> to <���>\n");
	return 1;
    }
    if(gold < 1 || gold > 1000000)
    {
	tell_object(me,"һ��ֻ��תһ��һ�������ƽ�\n");
	return 1;
    }

    mygold = me->query("more_money")*10000 + me->query("money")/10000;
    if(gold > mygold)
    {
	tell_object(me,"���Ǯׯ��û����ô����\n");
	return 1;
    }

    user = find_player(username);
    if(!user || !userp(user))
    {
	tell_object(me,"�Ҳ���������\n");
	return 1;
    }

    if(user == me)
    {
	tell_object(me,"�Լ����Լ�ת�ʣ��㵷ʲô�ң�\n");
	return 1;
    }

    if(!living(user))
    {
	tell_object(me,user->query("name")+"�������أ���"+gender_self(user->query("gender"))+"��������˵�ɡ�\n");
	return 1;
    }

    if(user->query_temp("doing_transfer"))
    {
	tell_object(me,"��Ȼ�ɣ�"+user->query("name")+"����ת�ʡ�\n");
	return 1;
    }
    user->set_temp("doing_transfer",1);
    me->set_temp("doing_transfer",1);
    tell_object(user,HIR+me->query("name")+"("+me->query("id")+")��׼��������˻�תǮ��\n"NOR);
    tell_object(me,"Ϊ��ȷ����ȫ���ڸ�"HIW+user->query("name")+"("+username+")"NOR+"ת��ǰ��������ݱ�ʶ��");
    input_to("get_biaoshi", 1,me,gold,username);
    return 1;
}
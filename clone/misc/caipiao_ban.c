// ��ƱͶעϵͳ made by Ҷ���(sunyc)@kync 2001/1/26
// remodify by Sunyc@kync 2002/7/24
// remodify By Sunyc@kync.tomud.com 5555 2002/11/24
// �������𣬿����ۼƣ�Ҳ��ֻ��gold��
// ��Ϊ30ѡ7
#include <ansi.h>
#include <localtime.h>
inherit ITEM;
inherit F_SAVE;
mixed *all_biao;
// int i,j,z;
static string *touzhu;
int do_read(string);
int do_ya(string);
void enough_rest();
string show_player();
void auto_post(string title,string body);
void create()
{
    set_name(HIG"��ƱͶע��"NOR, ({ "touzhu ban","touzhu","ban"}) );
    set("long",
      "���ǡ�Ϧ�����֡�ȫ����ҵĲ�ƱͶע�塣\n"
      "��ι����Ʊ��read rules��\n");
    set("unit", "��");
    set("no_put", 1);
    set("no_get", 1);
    set_weight(900000000);
    seteuid(getuid());
    set("times",1);
    restore();
}

void init()
{
    add_action("do_read", "read");
    add_action("do_ya","touzhu");
    add_action("do_duijiang","duijiang");
}
string query_save_file()
{
    return DATA_DIR + "caipiao/caipiao";
}
void enough_rest()
{
    delete_temp("busy");
}
int do_ya(int arg)
{
    object me,caipiao;
    mapping biao;
    string str;
    int i;
    restore();
    me=this_player();
    str="";
    if(!intp(arg) || !arg)
    {
        if(query("end_ya") || query("duijiang"))            
            return notify_fail("��ֹʱ���ѹ������´��������......\n");
        if (query_temp("busy"))        
            return notify_fail("���Ժ���������...\n");
        if(me->query("money")/10000<10)
            return notify_fail("Ǯׯ����Ҫ��ʮ���ƽ����Ͷע��\n");
        tell_object(me,"��ѡ7��30���ڵĺ��룬�ö��Ÿ�����\n");
        tell_object(me,"���磺2,3,4,5,6,7,8\n");
        tell_object(me,"��������-1���л�ѡ��\n");       
        tell_object(me,"����������ѡ��");
        input_to("touzhu_1",me);
        return 1;
    }
    else{
        message_vision("$N��ͶƱ��д�ú��ӽ���ͶƱ�塣����ͻȻ������һ�Ų�Ʊ��$N��æ����������\n",me);
        me->add("money",-100000);
        tell_object(me,"Ǯׯ�Ѿ��۳�����ʮ���ƽ�����"+query("kaijiang_cdate")+"���ȴ�����ɣ�\n");
        tell_object(me,HIR"�ǣϣϣġ��̣գã� ף�����ˣ�\n"NOR);
        caipiao=new("/clone/misc/caipiao.c");
        caipiao->set("kaijiang_date",query("kaijiang_cdate"));
        //���һ�������ַ���
        for(i=0;i<sizeof(me->query_temp("z_num"));i++)
            str+=me->query_temp("z_num")[i]+" ";
        caipiao->set("z_num",str);
        caipiao->set("times",query("times"));
        caipiao->move(me);
        caipiao->set("crypt",oldcrypt(str,0));
        biao = ([
          "id":me->query("id"),
          "name"  :me->name(1),
          "z_num" :str,
          "z_num_all":me->query_temp("z_num"),
          "jieguo":"δ����",   
        ]);
        me->delete_temp("z_num");
        if( !pointerp(all_biao) ) all_biao = ({biao});
        else all_biao += ({biao});
        save();
        restore();
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);
        return 1;
    }
    return 1;
}

void touzhu_1(string num,object me)
{
    int i,z,j=0;
    int p=0;
    int *jieguo=({});
    string str,*tmp=({});
    if(!num || num=="") 
    {
        tell_object(me,"��ѡ7��1-30�еĺ��룬�ö��Ÿ�����\n");
        tell_object(me,"���磺2,3,4,5,6,7,8\n");
        tell_object(me,"��������-1���л�ѡ��\n");       
        tell_object(me,"����������ѡ��");
        input_to("touzhu_1", me);
        return;
    }
    if(atoi(num)==-1)
    {
        i=0;
        z=0;
        str="";
        while(p!=7)
        {
            i=random(30)+1;
            if(member_array(i,jieguo)!=-1) continue;
            else 
            {
                jieguo+=({i});
                p++;
                continue;
            }
        }
        for(i=0;i<sizeof(jieguo);i++)
            str+=jieguo[i]+" ";
        me->set_temp("z_num",jieguo);       
        write("\n����Ͷע����Ϊ"HIR+str+NOR"����ȷ��ô?[y/n]��");
        input_to("yn",me);
        return;
    }   
    touzhu=explode(num,",");
    str="";
    for(i=0;i<sizeof(touzhu);i++)
    {
        if(!intp(z=atoi(touzhu[i])) || z<1 || z>30 || sizeof(touzhu)!=7) {j=1;break;}
        if(member_array(z,tmp)==-1)
            tmp+=({z});
        str+=" "+z;
    }
    if(sizeof(tmp)!=7) j=1;
    if(j) 
    {
        tell_object(me,"��ѡ7��1-30�еĺ��룬�ö��Ÿ�����\n");
        tell_object(me,"���磺2,3,4,5,6,7,8\n");
        tell_object(me,"��������-1���л�ѡ��\n");       
        tell_object(me,"����������ѡ��");
        input_to("touzhu_1", me);
        return;
    }
    me->set_temp("z_num",touzhu);
    write("\n����Ͷע����Ϊ"HIR+str+NOR"����ȷ��ô?[y/n]��");
    input_to("yn",me);
    return;
}
void yn(string yn,object me)
{
    if( (yn[0]!='y' && yn[0]!='Y') ) {
        me->delete_temp("z_num");
        write("\n�ðɣ�������Ͷע��");
        tell_object(me,"��ѡ7��1-30�еĺ��룬�ö��Ÿ�����\n");
        tell_object(me,"���磺2,3,4,5,6,7,8\n");
        tell_object(me,"����������ѡ��");
        input_to("touzhu_1", me);
        return;
    }
    else {
        write("\n����������...\n");
        do_ya(1);
        return;
    }
}

//void check(string yn,object me)
void check(object me)
{
    int money=0;
    int i;
 /*   if( oldcrypt(me->query_temp("check"),yn)!=yn) {
        write("�Բ����������У�������󣬲��ܸ���������\n");
        me->delete_temp("check");
        return;
    }
    else {   */
        write("\n��ϲ�����˱��ڴ�...\n");
        me->delete_temp("check");
        write("ok...��ʼ����\n");
        switch (all_biao[me->query_temp("num")]["jieguo"])
        {
        case "�صȽ�":money=query("last_gold");
            break;
        case "һ�Ƚ�":money=query("last_gold")/5;
            break;
        case "���Ƚ�":money=query("last_gold")/10;
            break;
        case "���Ƚ�":money=query("last_gold")/100;
            break;
        case "�ĵȽ�":money=query("last_gold")/1000;
            break;
        }
        for(i=0;i<money;i++)
        {
            me->add("money",10000);
        }
        write(HIR"������"+chinese_number(money)+"���ƽ�,�Ѿ���������˻���\n");
        message("sendto_alluser",HIW"����̶���ʡ���"+HIC" "+me->query("name")+HIW" ����"+HIY" "+chinese_number(money)+HIW" ���ƽ��Ѿ������ʻ���\n"NOR,users());
        all_biao[me->query_temp("num")]["jieguo"]="�Ѷҽ�";
        //all_biao-=({all_biao[me->query_temp("num")]});
        save();//����
        restore();
        me->delete_temp("num");
        me->delete_temp("check");
        remove_call_out("enough_rest");
        call_out("enough_rest", 1);
        return;
 //   }
}

int do_read(string arg)
{
    object me;
    me = this_player();

    if(arg == "rules")
    {
        write("����Ʊϵͳ�Ѿ���ͨ����ӭ���ǰ�����ʡ�\n");
        write("Ͷע����touzhu\n");
        write("��ѯ����read biao\n");
        write("��ѯ��������read duijiang\n");
        write("��ʹ��duijiangָ���Ľ����Զ��������ʻ���\n");
        return 1;
    }
    if(arg == "biao")
    {
        restore();
        /*if( !pointerp(all_biao) || !sizeof(all_biao) ) 
        {
            write("\n��û���˿�ʼͶע��\n");
            return 1;
        }*/
        write(show_player());
        return 1;
    }
    if(arg == "duijiang")
    {
        write("�ҽ�ϸ��\n");
        write("�صȽ����߸�����ȫ���Ǻϡ�      ����ȫ���ۼƽ���.\n");
        write("һ�Ƚ����������������Ǻϡ�      ����ȫ���ۼƽ���/5.\n");
        write("���Ƚ���������������Ǻ�        ����ȫ���ۼƽ���/50.\n");
        write("���Ƚ��������ĸ������Ǻ�        ����ȫ���ۼƽ���/100.\n");
        write("�ĵȽ����������������Ǻ�        ����ȫ���ۼƽ���/1000.\n");
        write("ף�����ʹ��!\n");
        return 1;
    }
    else        write("��Ҫ��ʲô�����������read rules�����������read biao,�ҽ�������read duijiang��\n");
    return 1;
}
string show_player()
{
    int z,j,k,i,h, m;
    string str="";
    int *str_te,*str_1,*str_2,*str_3,*str_4,*str_5,*list, *str_old;
    mapping name;
    restore();
    i=0;
    if(!query("duijiang"))
    {
        h=sizeof(all_biao); 
        str+=HIW"���ڲ�Ʊ���� "HIG+chinese_number(sizeof(all_biao))+HIW" λ���Ͷע��Ͷע״�����£�\n"NOR;
        str+="���������������ש����������������������ש�������\n";
        while (i<h)
        {
            name=all_biao[i];
            /*if (strlen(name["name"])==6)
                str+= sprintf("��%-28s��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);//ɾ��name["jieguo"]ǰ(int)name["t_num"] 
            else if(strlen(name["name"])==4)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+" "NOR,(int)name["z_num"],name["jieguo"],);
            else if(strlen(name["name"])==8)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
           else if(strlen(name["name"])==1)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
           else if(strlen(name["name"])==3)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
           else if(strlen(name["name"])==5)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
           else if(strlen(name["name"])==7)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
           else if(strlen(name["name"])==9)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
            else if(strlen(name["name"])==10)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
            else if(strlen(name["name"])==2)
                str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);*/
			str+= sprintf("��%-12s��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
			i++;
        }
        str+="���������������ߩ����������������������ߩ�������\n"NOR;
        if (query("end_cdate")) str+=HIW"����Ͷע��ֹʱ�䣺"HIY+query("end_cdate")+HIW"\n���ڲ�Ʊ����ʱ�䣺"HIM+query("kaijiang_cdate")+"\n"NOR;
        else str+=HIR"���ڲ�Ʊ�Ѿ���ֹ����,"HIW"����ʱ�䣺"HIG+query("kaijiang_cdate")+HIW"��\n"NOR;
        str+=HIW"���ڲ�Ʊ�ۼƽ���"HIY+query("all_gold")+HIG" ���ƽ�\n"NOR;
        return "/feature/more.c"->start_more(str);
    }
    str_te=str_1=str_2=str_3=str_4=str_5=list=str_old=({});
    str=HIW"�� "HIY+chinese_number(query("times")-1)+ HIW" �ڲ�Ʊ���ѿ�����"+HIR+query("last_z_num_str")+NOR+"\n";
    str+=HIW"���� "HIG+chinese_number(sizeof(all_biao))+HIW" �����Ͷע���н�������£�\n"NOR;
    i=0;
    h=sizeof(all_biao);
    for(i=0;i<h;i++)
    {
        k=0;
        for(z=0;z<sizeof(query("last_z_num"));z++)
        {
            j=all_biao[i]["z_num_all"][z];
            if(member_array(z,query("last_z_num"))!=-1) k++;
        }

		if ( all_biao[i]["jieguo"] == "�Ѷҽ�")
			str_old+=({i});
		else
		{
        switch (k){
        case 7: 
            str_te+=({i});
            all_biao[i]["jieguo"]="�صȽ�";
            break;
        case 6:
            str_1+=({i});
            all_biao[i]["jieguo"]="һ�Ƚ�";
            break;
        case 5:
            str_2+=({i});
            all_biao[i]["jieguo"]="���Ƚ�";
            break;
        case 4:
            str_3+=({i});
            all_biao[i]["jieguo"]="���Ƚ�";
            break;
        case 3:
            str_4+=({i});
            all_biao[i]["jieguo"]="�ĵȽ�";
            break;
        default:
            str_5+=({i});
            all_biao[i]["jieguo"]="�޽�";
            break;
        }
		}
    }
    save();
    list+=str_te+str_1+str_2+str_3+str_4+str_old;
    str_te=str_1=str_2=str_3=str_4=str_5=str_old=({});
    str+="���������������ש����������������������ש�������\n";
    str+= sprintf("��%-12s��%-22s��%-6s��\n","�����","  Ͷ   ע   ��   ��   ","���н�");
    str+="�ǩ������������贈���������������������贈������\n";
    z=0;
    h=sizeof(list);
    set("zhongjiang_num",h);
	m = 0;
    while (z<h)
    {
        i=list[z];
        name=all_biao[i];
        /*if (strlen(name["name"])==6)
            str+= sprintf("��%-28s��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==4)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+" "NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==8)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==1)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==2)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==3)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==5)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==7)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==9)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
        else if(strlen(name["name"])==10)
            str+= sprintf("��%-27s ��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);*/
		str+= sprintf("��%-12s��%22s��%-6s��\n",HIR+name["name"]+NOR,(int)name["z_num"],name["jieguo"],);
		if ( name["jieguo"] != "�Ѷҽ�" )
			m++;
        z++;
    }
    list=({});
    str+="���������������ߩ����������������������ߩ�������\n"NOR;
	str+=HIW"������δ�ҽ�ע����"HIM+chinese_number(m)+HIW"\n"NOR;
    str+=HIW"���ڲ�Ʊ����ʱ�䣺"HIG+query("start_cdate")+HIW"\n"NOR;
    str+=HIW"���ڲ�ƱԤ�ƽ���"HIY+query("all_gold")+HIW" ���ƽ�\n"NOR;
    return "/feature/more.c"->start_more(str);
}
int do_duijiang()//�ҽ�ָ��
{
    int i,j,k,m,n;
    object me;
    me = this_player();
    restore();
    if(!query("duijiang"))
        return notify_fail("��δ���ҽ�ʱ�䣡\n");
    if (query_temp("busy"))
        return notify_fail("�Ժ�........\n");
    set_temp("busy",1);
    j=sizeof(all_biao);
    k=0;
	i=0;
	m = 0;
	n = 0;
    while ( i < j )
    {
        if ( all_biao[i]["id"]==me->query("id") && all_biao[i]["name"]==me->query("name") )
        {
			n = 1;
			if ( all_biao[i]["jieguo"] != "�Ѷҽ�" && all_biao[i]["jieguo"] != "�޽�" ) 
			{
				k = i + 1;
				break;
			}
			else if ( all_biao[i]["jieguo"] == "�Ѷҽ�" )
				m = 1;
			else if ( all_biao[i]["jieguo"] == "�޽�" )
				m = 2;
        }
        i++;
    }
    delete_temp("busy");
    if ( !n || n == 0 ) return notify_fail("�㲢û�����Ʊѽ��\n");
    else if ( k )
    {
        me->set_temp("check",all_biao[k-1]["z_num"]+" "+all_biao[k-1]["t_num"]);
        me->set_temp("num",k-1);
        write("�����н�������"+me->query_temp("check")+"��\n");
     //   write("����������У����:");
        //input_to("check",me);
		check(me);
        return 1;
    }
	else if( m == 1 ) return notify_fail("���Ѿ��ҹ����ˣ�\n");
    else if( m == 2 ) return notify_fail("�����û�н������Ҹ�ƨ��\n");
}

void auto_post(string title,string body)
{
    mapping note;
    note = allocate_mapping(4);
    note["title"] = title;
    note["author"] ="��Ʊ��";
   // "/cmds/std/news.c"->done_post(this_object(),note,body);��ע�͵����������콱
    return;
}
void clean_data()
{
    all_biao=({});
    save();
    restore();
}

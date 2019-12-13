//��ʯ��ȡϵͳ 

#include <dbase.h>
#include <ansi.h>

string *b_names = ({
  "��",
  "��",
  "��",
  "��",
  "��",
  "��",
  "��",
  "���", 
  "���", 
  "����", 
  "ˮ��", 
  "��ɳ", 
  "è��", 
  "��ʯ", 
  "��֮���",
  "��֮���",
  "��֮����",
  "��֮ˮ��",
  "��֮��ɳ",
  "��֮è��",
  "��֮��ʯ",
  "����",
  "���",
  "ɭ��",
  "����",
  "����",
  "��ϼ",
  "ɳĮ",
  "��֮��",
  "��֮��",
  "��֮��",
  "��֮��",
  "��֮��",
  "��֮��",
  "��֮��",
});

string *names = ({
  "hong",
  "blue",
  "green",
  "qing",
  "huang",
  "zi",
  "cheng",
  "manao",
  "feicui",
  "chengyu",
  "shuijing",
  "jinsha",
  "maoyan",
  "zuanshi",
  "god manao",
  "god feicui",
  "god chengyu",
  "god shuijing",
  "god jinsha",
  "god maoyan",
  "god zuanshi",
  "sun",
  "sky",
  "forest",
  "sea",
  "fire",
  "sunshine",
  "sand",
  "justice light",
  "mercy light",
  "earth light",
  "sea light",
  "fire light",
  "gods light",
  "love light",
});

//�洢�鱦
int do_cun(string arg)
{
	string isbind;
	object ob;
	string name;

	isbind = "";
	
	if (!living(this_object()))
		return 0;
	
	if( !arg || !(ob = present(arg, this_player())) )
		return notify_fail("��Ҫ���ʲô�鱦��\n");		

	if ((sscanf(arg, "%s baoshi",name) != 1 ))
		return notify_fail("��Ҫ���ʲô�鱦��\n");

	if (!ob->query("zhubao_save"))
		return notify_fail("��Ҫ���ʲô�鱦��\n");

	if( ob->query("bind_master_level") )
	{
		isbind = "_bind";
        //return notify_fail("�󶨵���Ʒ���ܴ�š�\n");
	}
	
	if ( this_player()->query("baoshi_size"+isbind) >= 300 )
		return notify_fail(this_object()->query("name")+"˵�����͹٣�������ڱ���ı�ʯ�����ѵִ����ޡ�\n");
	
	message_vision("$N�����ϵ�" + ob->query("name") + "�ó���������鱦�ꡣ\n", this_player());

	if (!this_player()->query("baoshi_size"+isbind))
		this_player()->set("baoshi_size"+isbind, 1);
	else
		this_player()->add("baoshi_size"+isbind,1);

	if (!this_player()->query("baoshi_save"+isbind+"/" + name))
		this_player()->set("baoshi_save"+isbind+"/" + name,1);
	else
		this_player()->add("baoshi_save"+isbind+"/" + name,1);

    destruct(ob);
    return 1;
}

//ȡ�鱦
int do_qu(string arg)
{
	object ob;
	string name, isbind;
	int bind;

	isbind = "";
	
	if (!living(this_object()))
		return 0;
	
	if( !arg )
		return notify_fail("��Ҫȡ��ʲô�鱦��\n");

	if ( sscanf(arg, "%s,%d", arg, bind) == 2  )
	{
		if ( bind ) 
			isbind = "_bind";
	}

	if ( sscanf(arg, "%s baoshi",name) != 1 )
		return notify_fail("��Ҫȡ��ʲô�鱦��\n");

	if (!this_player()->query("baoshi_size"+isbind) 
		|| !this_player()->query("baoshi_save"+isbind) 
		|| this_player()->query("baoshi_size"+isbind) < 1)
		return notify_fail("��Ҫȡ��ʲô�鱦��\n");
	
	if (!this_player()->query("baoshi_save"+isbind+"/" + name) 
		|| this_player()->query("baoshi_save"+isbind+"/" + name) < 1)
		return notify_fail(this_object()->query("name")+"˵�����͹��ڱ�����Ĵ��������鱦�ɣ�\n");

	if (this_player()->query("baoshi_size"+isbind) < 1)
		this_player()->delete("baoshi_size"+isbind);
	else
		this_player()->add("baoshi_size"+isbind,-1);

	if (this_player()->query("baoshi_save"+isbind+"/" + name) < 1)
		this_player()->delete("baoshi_save"+isbind+"/" + name);
	else
		this_player()->add("baoshi_save"+isbind+"/" + name,-1);

	ob = new("/quest/baoshi/baoshis/"+name);

	if ( bind )
		ob->set("bind_master_level/"+this_player()->query("id"), 2);

	if (sizeof(all_inventory(this_player()))>50)
	{
		tell_object(this_player(), this_object()->query("name")+"˵�����͹٣���������ƺ�װ���¶����˰ɣ�\n");
		destruct(ob);
		return 1;
	}

	if ((int)this_player()->query_encumbrance() + ob->weight() > (int)this_player()->query_max_encumbrance())
	{
		tell_object(this_object()->query("name")+"˵�����͹٣���ĸ��ع�����Ŷ��������ھ�Ҫȡ��\n");
		destruct(ob);
		return 1;
	}
	
	if (ob->move(this_player()))
		message_vision("$N���鱦��ȡ��" + ob->query("name") + "�Ž������ҡ�\n", this_player());
	
	return 1;
}


//��ѯ��ʯ
int do_chaxun(string arg)
{
	string isbind;
	string str;
	object me,obj;
	int i, num;
	
	if (!living(this_object()))
		return 0;

	isbind = "";
	
	me=this_player();
	
	if (arg)
	{
		if( wizardp(me))
		{
			obj = find_player(arg);
			
			if( !obj )
				obj = find_living(arg);
			
			if( !obj )
				obj = present(arg, environment(me));
        }
		else
			return 0;
    }
    
	if (!objectp(obj))
		obj=me;
    
	if ( (!obj->query("baoshi_size") 
			|| !obj->query("baoshi_save") 
			|| obj->query("baoshi_size") < 1) 
		&& (!obj->query("baoshi_size_bind") 
			|| !obj->query("baoshi_save_bind") 
			|| obj->query("baoshi_size_bind") < 1))
		return notify_fail(this_object()->query("name")+sprintf("˵����%s��δ�ڱ����Ź��κ��鱦��\n",obj==me?"��":obj->short(1)));
	
	str = "\n"+((obj==me)?"��":obj->query("name"))+"�ڱ��깲����� "HIW+obj->query("baoshi_size")+NOR" �Ų��󶨱�ʯ("HIY"�����������300"NOR")\n"
		+ "�� "HIW+obj->query("baoshi_size_bind")+NOR" �Ű󶨱�ʯ("HIY"�����������300"NOR")��\n\n"NOR;
	
	for ( num=0; num<2; num++ )
	{
		if ( num == 0 )
		{
			isbind = "";
			if ( !obj->query("baoshi_size"+isbind) 
				|| !obj->query("baoshi_save"+isbind) 
				|| obj->query("baoshi_size"+isbind) < 1 )
				continue;
			str += "���󶨵ı�ʯ�У�\n";
		} else {
			isbind = "_bind";
			if ( !obj->query("baoshi_size"+isbind) 
				|| !obj->query("baoshi_save"+isbind) 
				|| obj->query("baoshi_size"+isbind) < 1 )
				continue;
			str += "\n�󶨵ı�ʯ�У�\n";
		}
		for ( i=0; i < sizeof(names); i++ )
		{
			if (obj->query("baoshi_save"+isbind+"/"+names[i]) 
				&& obj->query("baoshi_save"+isbind+"/"+names[i]) > 0)
			{
				if (i == 0 || i%7 == 0)
				str+=sprintf("%-40s ��%s \n",HIR+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
				if (i == 1 || i%7 == 1)
				str+=sprintf("%-40s ��%s \n",HIB+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
				if (i == 2 || i%7 == 2)
				str+=sprintf("%-40s ��%s \n",HIG+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
				if (i == 3 || i%7 == 3)
				str+=sprintf("%-40s ��%s \n",HIC+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
				if (i == 4 || i%7 == 4)
				str+=sprintf("%-40s ��%s \n",HIY+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
				if (i == 5 || i%7 == 5)
				str+=sprintf("%-40s ��%s \n",HIM+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
				if (i == 6 || i%7 == 6)
				str+=sprintf("%-40s ��%s \n",YEL+b_names[i]+"��ʯ"NOR+"("+names[i]+" baoshi)",obj->query("baoshi_save"+isbind+"/"+names[i])+" ��");
			}
		}
	}
	write(str);
	return 1;
}
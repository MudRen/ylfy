// ��ʯ�ϳ� By Wenwu On 2006.9.23

// ��Ҫ�ļ��Ĵ��Ŀ¼
#define BAOSHIS_DIR "/quest/baoshi/baoshis/"
// �ɹ��ʣ�ֵԽ�߳ɹ���Խ�ߣ�
#define CHENG_GONG_INT 15

#include <ansi.h>

inherit F_CLEAN_UP;

string *file_name = ({
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

int main(object me, string arg)
{
	object ob, ob2, ob3, *inv, baoshi;
	string baoshi_name, new_baoshi_name;
	int i, v, bind_flag;

	if ( !arg )
		return notify_fail("������ʲô�������кϳɣ�\n");
	if( !objectp(ob = present(arg, me)) )
		return notify_fail("�����ϲ�û������������\n");
	if ( !ob->query("zhubao_save") )
		return notify_fail("�����������ܽ��кϳɡ�\n");
	if ( ob->query("b_lvl") > 28 )
		return notify_fail("�������������ټ����ϳ��ˡ�\n");

	inv = all_inventory(me);
	for ( i = 0; i < sizeof(inv); i++ )
	{
		if ( inv[i] == ob )
			continue;
		if ( !inv[i]->query("zhubao_save") )
			continue;
		if ( inv[i]->query("id") != ob->query("id") )
			continue;
		if ( inv[i]->query("b_lvl") != ob->query("b_lvl") )
			continue;

		if ( !objectp(ob2) )
		{
			ob2 = inv[i];
			continue;
		}

		if ( objectp(ob3) )
			break;

		ob3 = inv[i];
	}

	if ( !objectp(ob2) )
		return notify_fail("�����ϱ���������һ���Ķ����ſ��Ժϳɡ�\n");
	if ( !objectp(ob3) )
		return notify_fail("�����ϱ���������һ���Ķ����ſ��Ժϳɡ�\n");

	v = ob->query("b_lvl") - 1;
	baoshi_name = ob->query("name")+"("+ob->query("id")+")";

	// �󶨵ı�ʯ��Ƕװ������ôװ��Ҳ�ᱻ��
	bind_flag = 0;
	if ( mapp(ob->query("bind_master_level")) 
		|| mapp(ob2->query("bind_master_level")) 
		|| mapp(ob3->query("bind_master_level")) ) {
		bind_flag = 1;
	}

	destruct(ob);
	destruct(ob2);
	destruct(ob3);

	if ( v < 0 || v > sizeof(file_name) - 1 )
	{
		write("�ϳ�ʧ�ܣ�����ʧ������" + baoshi_name + "��\n");
		return 1;
	}

	if ( random(sizeof(file_name)+CHENG_GONG_INT) < v )
	{
		write("�ϳ�ʧ�ܣ�����ʧ������" + baoshi_name + "��\n");
		return 1;
	}

	baoshi = new(BAOSHIS_DIR+file_name[v+7]);
	new_baoshi_name = baoshi->query("name")+"("+baoshi->query("id")+")";
	if ( bind_flag == 1 )
		baoshi->set("bind_master_level/"+me->query("id"), 1);
	baoshi->move(me);
	message_vision("$N"WHT"������"+baoshi_name+WHT"�ɹ��ϳ���һ��"+new_baoshi_name+"\n"NOR, me);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : hecheng ��ʯӢ����
��; : ���԰�����ͬ�ֱ�ʯ�ϳɸ��߼��ı�ʯ��
HELP);
return 1;
}


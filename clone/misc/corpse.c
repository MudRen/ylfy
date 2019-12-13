// ʬ�� Write By Wenwu

inherit ITEM;

int decayed;

void create()
{
	set_name("����ʬ��", ({ "corpse" }) );
	set("long", "����һ������ʬ�塣\n");
	set("no_put",1);
	set("unit", "��" );
	decayed = 0;
	set_heart_beat(90);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short() { return name() + "(" + capitalize(query("id")) + ")"; }

protected void heart_beat()
{
	object me, env, *inv;
	int i;
	
	me = this_object();
	decayed++;
	
	// �������
	if ( !clonep(me) ) return;

	if ( !objectp(env = environment()) )
	{ // û�л���
		destruct(me);
		return;
	}

	switch ( decayed ) 
	{
		// ��ʼ����
		case 1:
			me->delete("valid_get_from"); // �����
			tell_room(env, query("name") + "��ʼ�����ˣ�����һ�����ŵĶ����\n");
			switch ( query("gender") ) 
			{
				// ��ʬ
				case "����":
					set_name("���õ���ʬ", ({ "corpse", "ʬ��" }) );
					break;
				// Ůʬ
				case "Ů��":
					set_name("���õ�Ůʬ", ({ "corpse", "ʬ��" }) );
					break;
				default:
					set_name("���õ�ʬ��", ({ "corpse", "ʬ��" }) );
			}
			set("long",	"���ʬ����Ȼ�Ѿ�����������һ��ʱ���ˣ���ɢ����һ�ɸ�ʬ��ζ����\n");
			break;
		// ����
		case 2:
			tell_room(env, query("name") + "���紵Ǭ�ˣ����һ�ߺ��ǡ�\n");
			set_name("��Ǭ�ĺ���", ({ "skeleton", "����" }) );
			set("long", "�⸱�����Ѿ���������ܾ��ˡ�\n");
			set("unit", "��" );
			break;
		// ���
		case 3:
			tell_room(env, "һ��紵������" + query("name") + "���ɹǻҴ�ɢ�ˡ�\n");
			inv = all_inventory(this_object());
			for ( i=0; i<sizeof(inv); i++ ) 
			{
				if ( inv[i] ) inv[i]->move(env);
			}
			destruct(me);
			break;
		default:
			destruct(me);
	}
}

int bind_get(object ob)
{
	object me;
	mixed flag;

	me = this_object();

	if ( !objectp(ob) ) return 0;
	if ( wizardp(ob) ) return 0;
	if ( !(flag = me->query("valid_get_from")) 
		|| !stringp(flag) )
		return 0;
	// �����Լ��ģ��޷���ȥ
	if ( flag != ob->query("id") ) return 1;

	return 0;
}
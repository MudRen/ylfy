// by mayue


inherit ROOM;

void create()
{
set("short", "�ӵ��ܶ�");	
	set("long", @LONG
������һ�������ʯ���������Ǽ�Ӳ��ʯ�ڣ�������Ҫ��ȥ�����������	
���ˡ�����ֻ��һ��һ����һ������Ӷ������ҷ������룬���ڹ�����  	
����ǽ����һ����ʯ��(bed)�����Ա�ʯ�ڵ�ɫ���кܴ�ͬ��͸��
б������⣬�㿴��ʯ������ǽ�����ƺ�����һЩ���ֺ�ͼ�Ρ�һ��
����ʯ���ϰ���һ��ʯϻ(xia)��
LONG
	);
//      set("outdoors", "wudujiao");
        set("sleep_room", 1);
//            set("no_fight", 1);	

/*
	set("exits", ([
		"eastup" : __DIR__"shixi",
//            "down" : __DIR__"wandu3",
//		"westdown" : __DIR__"wdsl3",
//		"north" : __DIR__"wandu2",
	]));
*/
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
       set("item_desc",([
"wall":"\n       ֻ��ʯ���Ͽ��š�����Ī�����ĸ����ɷ���Ĵ��֡�\n	
�����������ֽ���������񣬿̵�����������ÿ�������ƶ�����ͬ��\n	
       �Ա߻������С��,�㲻��������ϰ(lianxi)һ�¡�\n ",
"ǽ��":"\n       ֻ��ʯ���Ͽ��š�����Ī�����ĸ����ɷ���Ĵ��֡�\n	
�����������ֽ���������񣬿̵�����������ÿ�������ƶ�����ͬ��\n	
       �Ա߻������С�֣��㲻��������ϰ(lianxi)һ�¡�\n ",
         "bed":"\nһ������ͨͨ��ʯ����\n ",
         "xia":"\nһֻʯϻ�������Ǻ�ʯ������һ��ģ���֪���Ҳ��Ҵ򿪿�����\n ",
]));
set("mishi_sword",1);	
	setup();
//	replace_program(ROOM);
}
void init()
{
  add_action("do_lianxi", "lianxi");
  add_action("do_jump", "jump");
  add_action("do_open", "open");
}

int do_lianxi(string arg)
{

  object me=this_player();
int swordskill=(int)me->query_skill("sword", 1);	
int wumingskill=(int)me->query_skill("wuming-jianfa", 1);	
  int exp=(int)me->query("combat_exp");
  if( me->query("jing") < (int)(me->query("max_jing")/5))
    return notify_fail("���Ѿ�û�о�����ϰ�ˣ�\n");
//     if (!((string)me->query("family/family_name")=="�嶾��")	
if (!(int)me->query_temp("wuming_onbed"))	
    {
message_vision("$N���󽣾������ű��ϵ�ͼ�αȻ��˼��Σ�ֻ����һ��ڸ����\n", me);	
    }
  else
    {
message_vision("$N���󽣾����ű���ͼ�ε����ƱȻ��˼��Σ��������һ���ƺ�������ʲô��\n", me);	
if (wumingskill>300)
return notify_fail("�����ű���ͼ�αȻ������£������ƺ�ûʲô��������ˡ�\n");	
if (exp <= (wumingskill*wumingskill*wumingskill)/10)    	
	{
	  me->receive_damage("qi", 30);
	  return notify_fail("������ľ��鲻����ʼ�ղ��ܴ�ͼ������ʲô��\n");
	}
if (wumingskill >150 && swordskill>150 )	
	{
me->improve_skill("wuming-jianfa", (int)(me->query_int()));	
tell_object(me, "���ƺ����������һЩ����������������š�\n");	
	}
      else
	{
	  tell_object(me, "��Ĺ���̫���ˣ����������ͼ�����ص��������š�\n");
	}
    }
  me->receive_damage("jing", 30);
  return 1;
}
int do_jump(string arg)
{
  object me=this_player();
  if( !arg ||! (arg =="bed" || arg =="up" || arg =="down"))
       return 0;
  if( arg =="up"||arg=="bed"){
if ((int)me->query_temp("wuming_onbed") )	
              return notify_fail("���Ѿ��ڴ����ˣ����������������ˡ�\n");
me->set_temp("wuming_onbed",1);	
       message_vision("$P����һ��������ʯ��������������\n", me);
	tell_object(me, "��ֻ����һ˿˿���������´������پ�����һ��\n");
   }      
  if( arg =="down"){
if (!(int)me->query_temp("wuming_onbed") )	
              return notify_fail("���Ѿ��ڵ����ˣ��ұ������ɺ���ͳ��\n");
me->delete_temp("wuming_onbed");	
       message_vision("$P��ʯ��������������\n", me);
   }      
  return 1;
}
int valid_leave (object me, string dir)
{
if (me->query_temp("wuming_onbed"))	
      	 return notify_fail("���´����ߣ�����·Ҳ������\n");
  return 1;
}
int do_open(string arg)
{
  object me,ob;
  me=this_player();
  if( !arg || arg !="xia")
       return 0;
if( query("mishi_sword") < 1)	
              return notify_fail("���ʯϻ����������տ���Ҳ��\n");
add("mishi_sword", -1);	
message_vision(YEL"$P��ʯϻ��������ȡ��һ��"HIR"ԽŮ"HIY"����"HIC"����\n"NOR, me); 	
ob = new("/clone/weapon/yuenv");	
  ob->move(me);
message_vision(HIM"ͻȻƾ�վ���һ����,ڤڤ������һ���ն�������:�񼼺��,������Ե!ȥ��.....\n"	
HIY"��Х����,$N�������ѱ����ϰ��.\n"NOR, me);                 	
me->move("/d/taohua/lantian");          	
  return 1;
}

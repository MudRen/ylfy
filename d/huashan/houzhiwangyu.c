// ----/d/huashan/houzhiwangyu.c ----
// Room: /inherit/room/houzhiwangyu.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�˴�ԭ��һ��������Ƶ��ͱڣ���֪�������˴��ͱڵİ���Ӳ�ǿ���һ��ջ
������ջ������һ��ʮ���ɵ�����ʯ����ʯ������һ�ɣ�������һ������ʯ����
���������µĺ��ӡ� 
LONG
);
        set("exits", ([ /* sizeof() == 3 */
  "southdown" : __DIR__"liyubei",
  "west" : __DIR__"cunyangdaoguan",
//        "northup" : __DIR__"huashanjueding.c",	
    "1" : __DIR__"biwu1.c",
    "2" : __DIR__"biwu2.c",
    "3" : __DIR__"biwu3.c",
    "4" : __DIR__"biwu4.c",
]));

  set("no_fight",1);
        setup();
}
int valid_leave(object me, string dir)
{
    int age=(int)me->query("mud_age") / 86400 + 14;
    if (wizardp(me)
      || dir == "1" && age < 25 
      || dir == "2" && ( age >=25 && age <60 )
      || dir == "3" && ( age >= 60 && age <90 )
      || dir == "4" && age >= 90 )
      return 1;
   if (dir == "southdown" || dir == "west" || dir == "northup") return 1;
    return notify_fail("�㲻���Ե��Ǳ߱��䣡��\n");
}


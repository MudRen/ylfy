// Room: /d/kunlun/klsj2.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
��ǰ��ʯ��ֻ�б�����һ������㲻�����Ƶ�̧ͷһ����ԭ��ʯ�����Գ�
���˸ߴ��������������ѹ�˺��İ�ѩ������ʯ����ûѩ�����紵������ѩ
����ӭͷ���£��㲻�����˸����¡�
LONG
        );
        set("outdoors", "klsj2");
        set("exits", ([ 
  "southdown" : __DIR__"klsj1",
  "northeast" : __DIR__"klt",
]));
     
        setup();
}
int valid_leave(object me, string dir)
{
    object boot;
    int damage=80-me->query_skill("dodge",1)/10;
    boot=me->query_temp("armor/boots");
    if (dir=="northeast" && (!boot || boot->query("id")!="sandals")){
        if (damage<20){
            tell_object(me,HIW+"�����һ������������Σ�����ûˤ�ţ�\n"+NOR);
            return 1;
        }else
        me->receive_damage("qi",damage);
        me->receive_damage("jing",damage);
        return notify_fail(HIW+"�����һ����ˤ�˸��Ľų��죡\n"+NOR);
   }
   return 1;
}


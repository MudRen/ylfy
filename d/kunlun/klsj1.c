// Room: /d/kunlun/klsj1.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ʯ���ϻ��˲���Ļ�ѩ��·����ɽʯ��ᾣ����¾����ĵģ����������
Ҳû�С�ֻ�к�Х�ı�����������ѩ������ӭ��������
LONG
        );
        set("outdoors", "klsj1");
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sbxd",
  "northup" : __DIR__"klsj2",
]));

        setup();
}
int valid_leave(object me, string dir)
{
    object boot;
    int damage=80-me->query_skill("dodge",1)/10;
    boot=me->query_temp("armor/boots");
    if (dir=="northup" && (!boot || boot->query("id")!="sandals")){
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


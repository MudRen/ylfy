// Room: /d/cxwxm/longfeng.c
// marry 8,14
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"��"HIC"��"HIG"��"HIM"��"HIB"¥"NOR);
        set("long", 
"������ǳ��������ŵ����ң��ǵ�ϵ�������޷���������ģ�����\n"
"�Ļҳ����д���񣬿����ܾö�δ�������ˡ����������ܵ�ǽ�Ͽ��ŵ�\n"
""+HIW"ͼ"HIR"��"NOR+"(tuan)��ؾ��Ǳ��ŵľ������壡\n\n"

);
        set("item_desc", ([ /* sizeof() == 1 */
  "tuan" : HIW"ͼ���ϻ�����һ��һŮ�����䣬������ʲô��˼�أ�����Ҫ��ϸ�о���yanjiu��һ���ˡ�
\n\n"NOR,
]));
   
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"fanting",
]));

        setup();
}
void init()
{
        add_action("do_yanjiu", "yanjiu");
}
int do_yanjiu(string arg)
{
        object me = this_player();

    if( !arg || arg!="tuan" )
        {
        write("������ʲô��\n");
        return 1;
    }
     if ((me->query("family/family_name") == "����������")&&(int)me->query_skill("bianfu-hebi", 1) < 800)
    {
// message_vision(HIY"$N��ϸ���о���ǽ�ϵ�ͼ��������������ᡣ\n"NOR,me);
 message_vision(HIY"�������˸�skill,��ʱȡ����\n"NOR,me);
/*
                me->receive_damage("jing", 8 + random(5));
me->improve_skill("bianfu-hebi", me->query("int")*3);
*/
        if ( (int)me->query("jing") < 1){me->unconcious();}
    }
    else
        {
          message_vision(
                HIR "���о���һ���ǽ�ϵ�ͼ����ֻ����ͷ��Ŀѣ���ҽ���һ����\n" NOR, me);
                me->set("qi",1);
                me->unconcious();
                me->move(__DIR__"fanting");
                }
                return 1;
}

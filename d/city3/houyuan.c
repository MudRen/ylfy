// Room: /d/shaolin/hanshui1.c
// bye mei
inherit ROOM;
void create()
{
        set("short", "��Ժ");
        set("long", @LONG
�����Ǽ��տ͵�ĺ�Ժ��������������ר�Ÿ���ӭ
��ס��Ŀ��ˡ�
LONG);

        set("no_fight", 1);
        set("exits" , ([
             "south": __DIR__"kedian",
             "enter" : __DIR__"chexiang",
           ]));


        setup();
}
int valid_leave(object me, string exit)
{
      if (exit=="enter"){
        delete("exits/enter");
        message_vision("$Nսս������������\n");
        message("vision","���һ˦���ӣ���������������ת�ۼ��ܵ���Ӱ���١�\n", this_object());
      } 
      return 1;
}


//xiaolu.c by:pipip
inherit ROOM;
void create()
{
  set("short","ʯͷС·");
  set("long",
      "����һ��Сʯͷ�̳ɵ�С·�����ߺ�����ͨ��\n"
      "�����ɵ���ڼ䣬���������ǵ������ɺ�ˮ���ӵ�·��\n"
    );
  set("exits",([
      "west" : "d/xuantian/chi",
      "east" : "d/xuantian/lian",    
     ]));
 setup();
}
int valid_leave(object who ,string dir)
{
 if((string)who->query("family/family_name")!="������"
    &&(dir!="west"))
   return notify_fail("�㲻�������ɵ��ӣ�����ڻ��ǻؼ���ɡ�\n");
 return 1 ;
}


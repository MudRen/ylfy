#include <liebiao.h>
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
mapping *ch_name= ({
   ([  "name": "city",
       "city": "����",
       "o_city": "���� ����",
       "manager": "  ������֪�� ��ҩ��\n  ��֪��ʦү ̷�Ѽ�\n  �������ؽ� ʷ��ɽ",
       "count": random(500)+100000,
       "good_man": "  ��������\n  ������",
   ]),
});

int main(object me, string arg)
{
    string map,name,*pname,msg,name1,info,cmds;
    int i;
    if( !arg ) 
	{
    msg = HIY"map ��ͼ����ָ��ʹ��˵����\n"NOR;
    msg += "������������������������������������������������������������������������\n";
    msg += "map ��ʾ�������ļ���  ��ɫ�����㵱ǰ���ڵ�����\n";
    msg += "map here ���ı��ص�ͼ��\n";
    msg += "map main ����ȫ����ͼ��\n";
    msg += "map �������� ����ָ�������ĵ�ͼ��\n";
    msg += "������������������������������������������������������������������������\n";
    me->start_more(msg); 
    return 1; 
	}
    
    if( arg == "main" ) 
	{
       map = read_file("/doc/help/maps");
       me->start_more(map);
       return 1;  
	}
    
	if( arg == "here") 
	{ 
       name = environment(me)->query("outdoors");
       if( !name ) {
          name = file_name(environment(me));
          pname = explode(name,"/");
          name =  pname[1];
          }
       map = read_file("/doc/help/map/"+name+"-map");
       if( map ) 
	{
       name1 = environment(me)->query("short");
       map = replace_string(map, name1, BGRN+HIW+name1+NOR);
       for(i=0;i<sizeof(ch_name);i++) 
		{
       if( ch_name[i]["name"] == name )  
		{ 
       info = sprintf(HIY"\n%s"HIW"%-10s"HIY"%s"HIW"%-10s"HIY"%s"HIW"%-10s"HIY"\n%s"HIW"%d"NOR,"���������š���",name,"����    �ơ���",ch_name[i][name],"�����ڵ�������",ch_name[i]["o_city"],"����    �ڡ���",ch_name[i]["count"]);
       info += HIR"\n\n��������Ա��\n\n"+HIW+ch_name[i]["manager"];
       info += HIG"\n\n�������������ˣ�\n\n"+HIW+ch_name[i]["good_man"]; 
        }
       }
    }
     //else return notify_fail("Ŀǰ��վ��δ�ṩ�˵�ͼ��\n");
	else
	{
		me->command("maphere");
		return 1;
	}
       me->start_more(map);
       if(info) {
       msg = sprintf(CLR+"%-105s"+HBRED+"%s"," ","��   ��   ��   ��   Ѷ  ��\n\n"NOR+HIW"��һ����Ѷ��\n"NOR);
       info = msg+info;
       printf("== "HIY"�Ƿ�ο���������Ϣ"NOR" == (Y/N): ");
       input_to("info_here",cmds,info,me);
       }
   }
   else if ( stringp(map = read_file("/doc/help/map/"+arg)) )
   {
	   me->start_more(map);
   }
    else return notify_fail("���뿴����ĵ�ͼ��\n");
    return 1;
}
int info_here(string cmds,string info,object me) {
     switch(cmds) {
         case "Y":
                me->start_more(info);
         case "N":
                return 1;
         case "y":
                me->start_more(info);
         case "n":
                return 1;
         case "":
                return 1;
         default:
                return 1;
      }
     return 1;
} 

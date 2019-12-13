//arm.c

#include <ansi.h>
#include <liebiao.h>
#include <mudlib.h>
#include <combat.h>
inherit F_CLEAN_UP;
inherit F_UNANSI;

string name_temp(object ob,string type);

int main(object me, string arg)
{
        object ob;
        mapping pmap;
        int islook;
        mixed attack_points, dodge_points, parry_points,armor;
        object weapon,second_weapon;
        string line,tmp,wp1,wp2,skill_type;
        if (arg)
	{
                ob = find_player(arg);
                if (! ob) ob = find_living(arg);
                if (! ob) ob = present(arg, environment(me));
                if (! wizardp(me) && (! ob || me->query("couple/child") != ob->query("id"))) 
                {
                      islook=0;   //������ʦ���Ӳ��ܿ����幥��������ֵ
                }
                else
                {
                      islook=1;       //���Բ鿴ȫ����ֵ
                }
                if(!ob)
                {
                     return notify_fail("��Ҫ�쿴˭��װ����\n"); 
                }
               
                       
        }
          if (! ob)
          {
              ob = me;
              islook=1;       //���Բ鿴ȫ����ֵ
          }
          if( ob==me && me->is_ghost() ) 
          return notify_fail("��Щ����֮����������������������������˰ɣ�\n");
           line="";
           tmp="";
           wp1="----";
           wp2="----";
       
  	 weapon= ob->query_temp("weapon");
         second_weapon= ob->query_temp("secondary_weapon");
         if(weapon)
         { 
                 wp1=weapon->query("name");
                
         }
         if(second_weapon)
         {
                  wp2=second_weapon->query("name");
                 
         }
          
   	

 write(HIG+" ["+ob->query("name")+"] װ����������Ʒ��                    \n"NOR);                    
 line += sprintf(HIY"������������������������������������������������������������������������\n");  
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[ͷ��]__"NOR+BLU"   ������   "WHT"__[����]"NOR" %-20s"NOR"\n",name_temp(ob,"armor/head"), wp1);
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[����]__"NOR+BLU"   "NOR" o"BLU"��"NOR"o "NOR"   "WHT"__[����]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/neck"), name_temp(ob,"armor/wrists"));
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[����]__"NOR+BLU"   "WHT"�y"NOR"��"WHT"�y"NOR+BLU" ��"WHT"__[�ֲ�]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/surcoat"), name_temp(ob,"armor/hands"));
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[�·�]__"NOR+BLU" �|������"BLU"�|"NOR+WHT" __[����]"NOR" %-20s"NOR"\n",name_temp(ob,"armor/cloth"), name_temp(ob,"armor/armor"));
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[����]__"NOR+BLU" ��  ��     "WHT"__[����]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/shield"),name_temp(ob,"armor/waist"));
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[����]__"NOR"   "BLU" ��"HIR""NOR+BLU" ��   "WHT"__[����]"NOR" %-20s"NOR"\n",wp2, name_temp(ob,"armor/pants"));
 tmp += sprintf(""HIY"��"NOR"%20s "WHT"[��ָ]__"NOR+BLU" �{��  ���{ "WHT"__[�㲿]"NOR" %-20s"NOR"\n", name_temp(ob,"armor/finger"), name_temp(ob,"armor/boots"));
  tmp += sprintf(HIY"������������������������������������������������������������������������\n"NOR);
 line += tmp;
 if(islook)
 {
      //�������У����ܺ��м�
      //--------------------------------------------------------
        pmap = me->query_skill_prepare();
        if( objectp(weapon = me->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else if ( sizeof(pmap) == 0)
		skill_type = "unarmed";
	else if ( sizeof(pmap) == 1)
		skill_type = (keys(pmap))[0];
	else if ( sizeof(pmap) == 2)
	{
		if ( (keys(pmap))[0] >= (keys(pmap))[1] )
			skill_type = (keys(pmap))[0];
		else
			skill_type = (keys(pmap))[1];
	}
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DODGE);
	armor = to_int(sqrt(to_float(ob->query_temp("apply/armor")/1000))); //2016.8.13��� �˺�����
      //--------------------------------------------------------
        line += sprintf(""YEL"��"HIR"������������: "HIC"%7d\n"NOR, ob->query_temp("apply/damage"));
		line += sprintf(""YEL"��"HIM"�����ߵֿ���: "HIC"%7d\n"NOR, ob->query_temp("apply/armor"));
		line += sprintf(""YEL"��"HIM"���˺����⡿: "HIC"%4d%%\n"NOR, armor );
        line += sprintf(""YEL"��"HIR"���� �С�: " HIW "%10s\n"NOR,floatp(attack_points)?(attack_points+1+"")[0..<8]:(attack_points+1+""));
		line += sprintf(""YEL"��"HIM"���� �ܡ�: " HIW "%10s\n"NOR,floatp(dodge_points)?(dodge_points+1+"")[0..<8]:(dodge_points+1+""));
		line += sprintf(""YEL"��"YEL"���� �ܡ�: " HIW "%10s\n"NOR,floatp(parry_points)?(parry_points+1+"")[0..<8]:(parry_points+1+""));
     //--------------------------------------------------------------
     line += sprintf(HIM"������������������������������������������������������������������������\n"); 
 }  
     line += ob->suit(ob);   //��װ��Ϣ   
     line += sprintf(HIM"������������������������������������������������������������������������\n"NOR); 
       write(line);
 
        return 1;
}
string name_temp(object ob,string type)
{
    string name;
    object obj;
    if( objectp(obj=ob->query_temp(type)) ) 
    {
       name = obj->query("name");
       //name = filter_color(name);
    }
    else
    {
       name = "----";
    }
   return name;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: arm
 
���г���(��)Ŀǰ������Я����������Ʒ��
 
 
HELP );
        return 1;
}
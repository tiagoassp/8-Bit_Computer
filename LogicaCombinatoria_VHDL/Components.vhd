------------------------------------------------------------
-- Deeds (Digital Electronics Education and Design Suite)
-- VHDL Code generated on (15/06/2023, 19:42:51)
--      by Deeds (Digital Circuit Simulator)(Deeds-DcS)
--      Ver. 2.50.200 (Feb 18, 2022)
-- Copyright (c) 2002-2022 University of Genoa, Italy
--      Web Site:  https://www.digitalelectronicsdeeds.com
------------------------------------------------------------

--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY NOT_gate IS
  PORT( I: IN std_logic;
  	O: OUT std_logic );
END NOT_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF NOT_gate IS
BEGIN
  O <= (not I);
END behavioral;



--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY AND5_gate IS
  PORT( I0,I1,I2,I3,I4: IN std_logic;
        O: OUT std_logic );
END AND5_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF AND5_gate IS
BEGIN
  O <= (I0 and I1 and I2 and I3 and I4);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY AND6_gate IS
  PORT( I0,I1,I2,I3,I4,I5: IN std_logic;
        O: OUT std_logic );
END AND6_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF AND6_gate IS
BEGIN
  O <= (I0 and I1 and I2 and I3 and I4 and I5);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR2_gate IS
  PORT( I0,I1: IN std_logic;
        O: OUT std_logic );
END OR2_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR2_gate IS
BEGIN
  O <= (I0 or I1);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR3_gate IS
  PORT( I0,I1,I2: IN std_logic;
        O: OUT std_logic );
END OR3_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR3_gate IS
BEGIN
  O <= (I0 or I1 or I2);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR4_gate IS
  PORT( I0,I1,I2,I3: IN std_logic;
        O: OUT std_logic );
END OR4_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR4_gate IS
BEGIN
  O <= (I0 or I1 or I2 or I3);
END behavioral;


--------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

ENTITY OR8_gate IS
  PORT( I0,I1,I2,I3,I4,I5,I6,I7: IN std_logic;
        O: OUT std_logic );
END OR8_gate;

--------------------------------------------------------------------
ARCHITECTURE behavioral OF OR8_gate IS
BEGIN
  O <= (I0 or I1 or I2 or I3 or I4 or I5 or I6 or I7);
END behavioral;



